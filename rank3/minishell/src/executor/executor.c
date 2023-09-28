/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 02:27:35 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/28 14:00:58 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	run_command(t_exe *executor, char **split_cmd)
{
	char	*path;

	path = get_cmd_path(executor->paths, split_cmd[0]);
	if (!path)
		error_exit("Command not found");
	if (execve(path, split_cmd, executor->minishell_envp) == -1)
	{
		ft_putstr_fd("Execve error", 2);
		error_exit("Execve error");
	}
}

void	execute_multiple_command(t_exe *executor)
{
	char	**cmd;
	int		index;

	index = 0;
	while (executor->commands[index])
	{
		cmd = ft_split(executor->commands[index], ' ');
		empty_array(cmd);
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
	if (executor->command_count == 1)
		execute_single_command(executor);
	else
	{
		execute_multiple_command(executor);
	}
}
