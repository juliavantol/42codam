/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 02:27:35 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/03 17:35:13 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	run_command(t_exe *executor, char **command)
{
	char	*path;

	path = get_cmd_path(executor->paths, command[0]);
	if (!path)
		error_exit("Command not found");
	if (execve(path, command, executor->minishell_envp) == -1)
		error_exit("Execve error");
}

void	last_command(t_exe *executor, char **cmd)
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
		run_command(executor, cmd);
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(pid, &status, 0);
}

void	handle_multiple_command(t_exe *executor, char **cmd)
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
		run_command(executor, cmd);
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
	char	**cmd;
	pid_t	pid;

	if (pipe(fds) < 0)
		error_exit("Error with opening the pipe");
	pid = fork();
	if (pid < 0)
		error_exit("Error with fork");
	if (pid == 0)
	{
		cmd = ft_split(executor->commands[0], ' ');
		run_command(executor, cmd);
		empty_array(cmd);
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(pid, &status, 0);
}

void	start_executor(t_exe *executor)
{
	char	**cmd;
	int		index;

	index = 0;
	executor->fd_in = STDIN_FILENO;
	if (executor->command_count == 1)
		handle_single_command(executor);
	else
	{
		while (index < executor->command_count - 1)
		{
			cmd = ft_split(executor->commands[index], ' ');
			handle_multiple_command(executor, cmd);
			empty_array(cmd);
			index++;
		}
		cmd = ft_split(executor->commands[index], ' ');
		last_command(executor, cmd);
		empty_array(cmd);
		executor->fd_in = STDIN_FILENO;
	}
}
