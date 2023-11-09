/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 18:44:30 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/09 13:38:03 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	child_signal_handler(int signal_num)
{
	printf("\n");
	// printf("test: %d\n", 128 + signal_num);
	(void) signal_num;
}

void	init_child_signal_handler(void)
{
	signal(SIGINT, child_signal_handler);
	signal(SIGQUIT, child_signal_handler);
}

void	run_command(t_exe *executor, t_cmd *command)
{
	char	*path;
	char	**envp;
	char	**cmd;

	if (ft_strcmp(command->command_name, "exit") == true)
		exit_shell(executor, EXIT_SUCCESS, command);
	envp = convert_envp_to_char(executor);
	cmd = ft_split(command->command_name, ' ');
	path = get_cmd_path(executor, cmd[0], envp, 0);
	if (!path)
		error_exit("Command not found");
	restore_signals();
	if (execve(path, cmd, envp) == -1)
		error_exit("Execve error");
}

void	last_command(t_exe *executor, t_cmd *command)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		error_exit("Error with fork");
	if (pid == 0)
	{
		redirect_input(command);
		redirect_output(command);
		run_command(executor, command);
		exit(EXIT_SUCCESS);
	}
	else
	{
		init_child_signal_handler();
		dup2(executor->old_fds[WRITE], WRITE);
		if (WIFEXITED(executor->status))
			executor->exit_code = WEXITSTATUS(executor->status);
		else if (WIFSIGNALED(executor->status))
			executor->exit_code = 128 + WTERMSIG(executor->status);
	}
}

void	handle_command(t_exe *executor, t_cmd *command)
{
	pid_t	pid;

	if (pipe(executor->fds) < 0)
		error_exit("Error with opening the pipe");
	pid = fork();
	if (pid < 0)
		error_exit("Error with fork");
	if (pid == 0)
	{
		redirect_input(command);
		redirect_output(command);
		close(executor->fds[READ]);
		if (!command->output_redirection)
			dup2(executor->fds[WRITE], WRITE);
		run_command(executor, command);
		exit(EXIT_SUCCESS);
	}
	else
	{
		init_child_signal_handler();
		if (WIFEXITED(executor->status))
			executor->exit_code = WEXITSTATUS(executor->status);
		else if (WIFSIGNALED(executor->status))
			executor->exit_code = WTERMSIG(executor->status);
		close(executor->fds[WRITE]);
		dup2(executor->fds[READ], READ);
	}
}

void	start_executor(t_exe *executor)
{
	t_cmd	*head;

	head = executor->commands_list;
	handle_heredocs(executor);
	while (head != NULL)
	{
		if (!check_builtin(executor, head))
		{
			if (executor->index < executor->command_count - 1)
				handle_command(executor, head);
			else
				last_command(executor, head);
		}
		head = head->next;
		(executor->index)++;
	}
    while (wait(NULL) > 0)
    {
        dup2(executor->old_fds[READ], READ);
        dup2(executor->old_fds[WRITE], WRITE);
        free_command_list(executor);
    }
}
