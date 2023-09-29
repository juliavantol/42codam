/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 02:27:35 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/29 15:19:18 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	run_command(t_exe *executor, char **split_cmd)
{
	char	*path;

	path = get_cmd_path(executor->paths, split_cmd[0]);
	if (!path)
		error_exit("Command not found");
	if (execve("/usr/bin/ls", split_cmd, executor->minishell_envp) == -1)
	{
		error_exit("Execve error");
	}
}

void	execute_multiple_command(t_exe *executor, char **cmd)
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
		close(fds[READ]);
		dup2(fds[WRITE], OUTPUT);
		if (cmd)
			run_command(executor, cmd);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (executor->prev_pipe != -1)
		{
			//Close the read end of the previous pipe
			close(executor->prev_pipe);
		}
		executor->prev_pipe = fds[READ];
		close(fds[WRITE]);
		dup2(fds[READ], INPUT);
		waitpid(pid, &status, 0);
	}
}

void	execute_single_command(t_exe *executor)
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
	if (executor->command_count == 1)
		execute_single_command(executor);
	else
	{
		while (executor->commands[index])
		{
			cmd = ft_split(executor->commands[index], ' ');
			execute_multiple_command(executor, cmd);
			empty_array(cmd);
			index++;
		}
	}
}
