/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   old_executor.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 12:20:08 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/10 17:23:21 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

// void	child_signal_handler(int signal_num)
// {
// 	if (signal_num == SIGPIPE)
// 	{
// 		printf("heyyy\n");
// 	}
// 	else
// 		printf("\n");
// 	(void) signal_num;
// }

// void	init_child_signal_handler(void)
// {
// 	signal(SIGINT, child_signal_handler);
// 	signal(SIGQUIT, child_signal_handler);
// 	signal(SIGPIPE, child_signal_handler);
// }

// void	run_command(t_exe *executor, t_cmd *command)
// {
// 	char	*path;
// 	char	**envp;
// 	char	**cmd;

// 	if (ft_strcmp(command->command_name, "exit") == true)
// 		exit_shell(executor, EXIT_SUCCESS, command);
// 	envp = convert_envp_to_char(executor);
// 	cmd = ft_split(command->command_name, ' ');
// 	path = get_cmd_path(executor, cmd[0], envp, 0);
// 	if (!path)
// 		error_exit("Command not found");
// 	restore_signals();
// 	if (execve(path, cmd, envp) == -1)
// 		error_exit("Execve error");
// }

// void	last_command(t_exe *executor, t_cmd *command)
// {
// 	executor->pids[executor->index] = fork();
// 	if (executor->pids[executor->index] < 0)
// 		error_exit("Error with fork");
// 	if (executor->pids[executor->index] == 0)
// 	{
// 		redirect_input(command);
// 		redirect_output(command);
// 		run_command(executor, command);
// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 	{
// 		init_child_signal_handler();
// 		dup2(executor->old_fds[WRITE], WRITE);
// 		if (WIFEXITED(executor->status))
// 			executor->exit_code = WEXITSTATUS(executor->status);
// 		else if (WIFSIGNALED(executor->status))
// 			executor->exit_code = 128 + WTERMSIG(executor->status);
// 	}
// }

// void	handle_command(t_exe *executor, t_cmd *command)
// {
// 	if (pipe(executor->fds) < 0)
// 		error_exit("Error with opening the pipe");
// 	executor->pids[executor->index] = fork();
// 	if (executor->pids[executor->index] < 0)
// 		error_exit("Error with fork");
// 	if (executor->pids[executor->index] == 0)
// 	{
// 		redirect_input(command);
// 		redirect_output(command);
// 		close(executor->fds[READ]);
// 		if (!command->output_redirection)
// 		{
// 			dup2(executor->fds[WRITE], WRITE);
// 			close(executor->fds[WRITE]);
// 		}
// 		run_command(executor, command);
// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 	{
// 		close(executor->fds[WRITE]);
// 		dup2(executor->fds[READ], READ);
// 		close(executor->fds[READ]);
// 		init_child_signal_handler();
// 		if (WIFEXITED(executor->status))
// 			executor->exit_code = WEXITSTATUS(executor->status);
// 		else if (WIFSIGNALED(executor->status))
// 			executor->exit_code = WTERMSIG(executor->status);
// 	}
// }

// void	wait_for_all_child_processes(t_exe *executor)
// {
// 	int	index;
// 	int	status;

// 	index = 0;
// 	while (executor->pids[index])
// 	{
// 		waitpid(executor->pids[index], &status, 0);
// 		index++;
// 	}
// }

// void	start_executor(t_exe *executor)
// {
// 	t_cmd	*head;

// 	head = executor->commands_list;
// 	handle_heredocs(executor);
// 	while (head != NULL)
// 	{
// 		pipe(executor->fds);
// 		if (!check_builtin(executor, head))
// 		{
// 			if (executor->index < executor->command_count - 1)
// 				handle_command(executor, head);
// 			else
// 				last_command(executor, head);
// 		}
// 		head = head->next;
// 		(executor->index)++;
// 	}
// 	executor->pids[executor->index] = '\0';
// 	wait_for_all_child_processes(executor);
// 	dup2(executor->old_fds[READ], READ);
// 	dup2(executor->old_fds[WRITE], WRITE);
// 	free_command_list(executor);
// }
