/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 18:44:30 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/23 13:53:15 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "expander.h"

void	run_command(t_exe *executor, t_cmd *command)
{
	char	*path;
	char	**envp;

	if (ft_strcmp(command->command_name, "exit") == true)
		exit_shell(executor, EXIT_SUCCESS, command);
	restore_signals();
	envp = convert_envp_to_char(executor);
	expand_command(executor, command);
	if (ft_strcmp(command->command_name, ""))
		exit(EXIT_SUCCESS);
	path = get_cmd_path(executor, command->split[0], envp, 0);
	if (!path)
		return ;
	if (execve(path, command->split, envp) == -1)
		error_exit("Execve error");
}

void	single_command(t_exe *executor, t_cmd *command)
{
	int	status;

	// printf("before: [%s]\n", command->command_name);
	// start_expander(executor, command->command_name);
	// exit(1);
	if (ft_strcmp(command->split[0], "exit") == true)
		exit_shell(executor, EXIT_SUCCESS, command);
	if (parentprocess_builtins(executor, command))
		return ;
	executor->pids[executor->index] = fork();
	if (executor->pids[executor->index] == 0)
	{
		redirect_input(command);
		redirect_output(command);
		if (childprocess_builtins(executor, command))
			exit (EXIT_SUCCESS);
		run_command(executor, command);
	}
	init_child_signal_handler();
	waitpid(executor->pids[executor->index], &status, 0);
	if (WIFEXITED(status))
		executor->exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(executor->status))
		executor->exit_code = 128 + WTERMSIG(status);
}

void	ft_fork(t_exe *executor, t_cmd *command)
{
	executor->pids[executor->index] = fork();
	if (executor->pids[executor->index] == 0)
	{
		redirect_input(command);
		redirect_output(command);
		dup2(executor->input_fd, STDIN_FILENO);
		close(executor->fds[READ]);
		dup2(executor->fds[WRITE], STDOUT_FILENO);
		close(executor->fds[WRITE]);
		init_child_signal_handler();
		if (executor->index > 0)
			close(executor->input_fd);
		if (childprocess_builtins(executor, command))
			exit (EXIT_SUCCESS);
		run_command(executor, command);
	}
	init_child_signal_handler();
}

void	run_pipeline(t_exe *executor)
{
	t_cmd	*head;

	head = executor->commands_list;
	executor->input_fd = STDIN_FILENO;
	while (head != NULL)
	{
		if (head->next)
			pipe(executor->fds);
		if (!parentprocess_builtins(executor, head))
			ft_fork(executor, head);
		close(executor->fds[WRITE]);
		if (executor->index > 0)
			close(executor->input_fd);
		executor->input_fd = executor->fds[READ];
		head = head->next;
		(executor->index)++;
	}
	executor->pids[executor->index] = '\0';
	wait_for_all_child_processes(executor);
}

void	start_executor(t_exe *executor)
{
	t_cmd	*head;

	head = executor->commands_list;
	handle_heredocs(executor);
	if (executor->command_count == 1)
		single_command(executor, head);
	else
		run_pipeline(executor);
	reset_executor(executor);
}
