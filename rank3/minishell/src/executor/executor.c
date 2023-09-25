/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 02:27:35 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/25 16:50:04 by juvan-to      ########   odam.nl         */
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

void	start_pipe(t_exe *executor, char **cmd)
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
		run_command(executor, cmd);
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(pid, &status, 0);
}

void	execute(t_exe *executor, char *str)
{
	char	**commands;
	char	**cmd;

	commands = ft_split(str, '|');
	cmd = NULL;
	while (*commands)
	{
		cmd = ft_split(*commands, ' ');
		while (*cmd)
		{
			printf("%s\n", *cmd);
			cmd++;
		}
		commands++;
		cmd = NULL;
	}
	executor->paths = NULL;
}

