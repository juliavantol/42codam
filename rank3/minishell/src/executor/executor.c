/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 02:27:35 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/08 18:51:19 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	run_command(t_exe *executor, t_cmd *command)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(command->command, ' ');
	path = get_cmd_path(executor->paths, cmd[0]);
	if (!path)
		error_exit("Command not found");
	if (execve(path, cmd, executor->minishell_envp) == -1)
		error_exit("Execve error");
}

void	last_command(t_exe *executor, t_cmd *command)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		error_exit("Error with fork");
	if (pid == 0)
	{
		if (executor->fd_in != STDIN_FILENO)
		{
			dup2(executor->fd_in, STDIN_FILENO);
			close(executor->fd_in);
		}
		run_command(executor, command);
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(pid, &status, 0);
	waitpid(pid, &status, 0);
}

void	handle_multiple_command(t_exe *executor, t_cmd *command)
{
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) < 0)
		ft_error("Error with opening the pipe", errno);
	pid = fork();
	if (pid < 0)
		ft_error("Error with fork", errno);
	if (pid == 0)
	{
		if (executor->fd_in != STDIN_FILENO)
		{
			dup2(executor->fd_in, STDIN_FILENO);
			close(executor->fd_in);
		}
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[1]);
		run_command(executor, command);
	}
	else
	{
		close(fds[1]);
		executor->fd_in = fds[0];
	}
}

void	handle_single_command(t_exe *executor)
{
	int		fds[2];
	int		status;
	pid_t	pid;

	if (pipe(fds) < 0)
		error_exit("Error with opening the pipe");
	pid = fork();
	if (pid < 0)
		error_exit("Error with fork");
	if (pid == 0)
	{
		run_command(executor, executor->all_commands[0]);
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(pid, &status, 0);
}

void	start_executor(t_exe *executor)
{
	executor->fd_in = STDIN_FILENO;
	if (executor->command_count == 1)
		handle_single_command(executor);
	else
	{
		while (executor->index < executor->command_count - 1)
		{
			handle_multiple_command(executor, executor->all_commands[executor->index]);
			(executor->index)++;
		}
		last_command(executor, executor->all_commands[executor->index]);
		executor->fd_in = STDIN_FILENO;
	}
}
