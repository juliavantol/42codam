/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   01_executor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 02:27:35 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/12 18:46:00 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

// void	free_commands(t_exe *executor)
// {
// 	int i;

// 	i = 0;
// 	while (executor->all_commands[i])
// 	{
// 		free(executor->all_commands[i]->command);
// 		empty_int_array(executor->all_commands[i]->output_fds);
// 		i++;
// 	}
// }

// void	run_command(t_exe *executor, t_cmd *command)
// {
// 	char	*path;
// 	char	**cmd;

// 	cmd = ft_split(command->command, ' ');
// 	path = get_cmd_path(executor->paths, cmd[0]);
// 	if (!path)
// 		error_exit("Command not found");
// 	if (execve(path, cmd, executor->minishell_envp) == -1)
// 		error_exit("Execve error");
// }

// void	handle_single_command(t_exe *executor, t_cmd *command)
// {
// 	int		fds[2];
// 	int		status;
// 	pid_t	pid;

// 	check_output_redirections(executor, command);
// 	if (pipe(fds) < 0)
// 		error_exit("Error with opening the pipe");
// 	pid = fork();
// 	if (pid < 0)
// 		error_exit("Error with fork");
// 	if (pid == 0)
// 	{
// 		if (executor->fd_out != STDOUT_FILENO)
// 		{
// 			dup2(executor->fd_out, STDOUT_FILENO);
// 		}
// 		run_command(executor, command);
// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 		waitpid(pid, &status, 0);
// }

// void	handle_command(t_exe *executor, t_cmd *command, int *fds)
// {
// 	pid_t	pid;
// 	int		temp_fd;

// 	temp_fd = -1;
// 	pid = fork();
// 	if (pid < 0)
// 		ft_error("Error with fork", errno);
// 	if (pid == 0)
// 	{
// 		if (executor->fd_in != STDIN_FILENO)
// 		{
// 			dup2(executor->fd_in, STDIN_FILENO);
// 			close(executor->fd_in);
// 		}
// 		if (command->output_redirection == true)
// 		{
// 			if (executor->index == executor->command_count - 1)
// 			{
// 				dup2(executor->fd_out, STDOUT_FILENO);
// 				close(executor->fd_out);
// 			}
// 			else
// 			{
// 				temp_fd = dup(STDOUT_FILENO);
// 				dup2(executor->fd_out, STDOUT_FILENO);
// 				close(executor->fd_out);
// 				dup2(fds[WRITE], STDOUT_FILENO);
// 			}
// 		}
// 		else
// 			dup2(fds[WRITE], STDOUT_FILENO);
// 		run_command(executor, command);
// 		if (temp_fd != -1)
// 		{
// 			// dup2(fds[WRITE], STDOUT_FILENO);
// 			// dup2(temp_fd, STDOUT_FILENO);
//    			close(temp_fd);
// 		}
// 		exit(EXIT_SUCCESS);
// 	}
// }

// void	start_executor(t_exe *executor)
// {
// 	int fds[2];
// 	int status;
// 	int	index;

// 	if (executor->command_count == 1)
// 	{
// 		handle_single_command(executor, executor->all_commands[0]);
// 		return ;
// 	}
// 	executor->fd_in = STDIN_FILENO;
// 	while (executor->index < executor->command_count - 1)
// 	{
// 		if (pipe(fds) < 0)
// 			error_exit("Error with opening the pipe");
// 		check_output_redirections(executor, executor->all_commands[executor->index]);
// 		handle_command(executor, executor->all_commands[executor->index], fds);
// 		close(fds[WRITE]);
// 		executor->fd_in = fds[READ];
// 		(executor->index)++;
// 	}
// 	check_output_redirections(executor, executor->all_commands[executor->index]);
// 	handle_command(executor, executor->all_commands[executor->index], fds);
// 	index = 0;
// 	while (index < executor->command_count)
// 	{
// 		wait(&status);
// 		index++;
// 	}
// }
