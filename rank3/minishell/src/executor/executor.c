/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 02:27:35 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/27 16:22:43 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	run_command(t_exe *executor, char **split_cmd)
{
	char	*path;

	path = get_cmd_path(executor->paths, split_cmd[0]);
	if (!path)
		error_exit("Command not found");
	printf("%s\n", path);
	if (execve(path, split_cmd, executor->minishell_envp) == -1)
		error_exit("Execve error");
}

void	open_command_pipe(t_exe *executor, char **command)
{
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) < 0)
		error_exit("Error with opening the pipe");
	pid = fork();
	if (pid < 0)
		error_exit("Error with fork");
	if (pid == 0)
	{
		close(fds[0]);
		dup2(fds[1], 1);
		if (command != NULL)
			run_command(executor, command);
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], 0);
	}
}

int	loop_through_commands(t_exe *executor, char *str)
{
	char	**commands;
	char	**cmd;
	int		index;

	index = 0;
	commands = ft_split(str, '|');
	while (commands[index] != NULL)
	{
		cmd = ft_split(commands[index], ' ');
		// run_command(executor, cmd);
		open_command_pipe(executor, cmd);
		empty_array(cmd);
		index++;
	}
	empty_array(commands);
	return (0);
}

void	execute(t_exe *executor, char *str)
{
	int		fds[2];
	int		status;
	pid_t	pid;

	loop_through_commands(executor, str);
	return ;
	if (pipe(fds) < 0)
		error_exit("Error with opening the pipe");
	pid = fork();
	if (pid < 0)
		error_exit("Error with fork");
	if (pid == 0)
	{
		// loop through commands
		loop_through_commands(executor, str);
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(pid, &status, 0);
}
