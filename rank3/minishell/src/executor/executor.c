/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 02:27:35 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/26 14:21:42 by juvan-to      ########   odam.nl         */
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
		child_process(fds, pipex);
	else
	{
		close(fds[1]);
		dup2(fds[0], 0);
	}
}

void	open_shell_pipe(void)
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
		// loop through commands
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(pid, &status, 0);
}

int	loop_through_commands(char *str)
{
	char	**commands;
	char	**cmd;
	int		index;

	index = 0;
	commands = ft_split(str, '|');
	while (commands[index + 1] != NULL)
	{
		cmd = ft_split(commands[index], ' ');
		// start pipe for command
		empty_array(cmd);
		index++;
	}
	empty_array(commands);
	return (0);
}
