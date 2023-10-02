/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 02:27:35 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/02 13:00:39 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	redirect_last_command(t_exe *executor, char **cmd)
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
		dup2(OUTPUT, 1);
		run_command(executor, cmd);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

void	run_command(t_exe *executor, char **split_cmd)
{
	char	*path;

	path = get_cmd_path(executor->paths, split_cmd[0]);
	if (!path)
		error_exit("Command not found");
	if (execve("/bin/ls", split_cmd, executor->minishell_envp) == -1)
	{
		error_exit("Execve error");
	}
}

void	execute_multiple_command(t_exe *executor)
{
	int		fds[2];
	int		status;
	int		index;
	char	**cmd;
	pid_t	pid;

	index = 0;
	while (executor->commands[index])
	{
		cmd = ft_split(executor->commands[index], ' ');
		if (index < (executor->command_count - 1))
			pipe(fds);
		pid = fork();
		// child
		if (pid == 0)
		{
			if (index > 0)
			{
				dup2(fds[READ], INPUT);
				close(fds[READ]);
			}
			if (index < (executor->command_count - 1))
			{
				dup2(fds[WRITE], OUTPUT);
				close(fds[WRITE]);
			}
			run_command(executor, cmd);
			empty_array(cmd);
		}
		// parent
		else
		{
			if (index > 0)
				close(fds[READ]);
			if (index < (executor->command_count - 1))
				close(fds[WRITE]);
			waitpid(pid, &status, 0);
		}
		index++;
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
		execute_multiple_command(executor);
		return ;
		while (executor->commands[index])
		{
			cmd = ft_split(executor->commands[index], ' ');
			if (index == executor->command_count - 1)
				redirect_last_command(executor, cmd);
			else
				execute_multiple_command(executor);
			empty_array(cmd);
			index++;
		}
	}
}
