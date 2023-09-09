/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:17:48 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/08 12:09:29 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_command(char *cmd, t_pipex pipex)
{
	char	*path;

	if (pipex.cmd_split != NULL)
	{
		path = get_cmd_path(pipex.paths, cmd);
		if (!path)
			error_exit("Command not found");
		if (execve(path, pipex.cmd_split, pipex.full_envp) == -1)
		{
			ft_putstr_fd("Execve error", 2);
			error_exit("Execve error");
		}
	}
}

void	output(char *output, char *cmd, t_pipex pipex)
{
	pipex.outfile = open(output, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex.outfile < 0)
		error_exit("File couldn't be opened");
	if (access(output, R_OK) != 0 || access(output, W_OK) != 0)
		error_exit("Can't be read/written");
	dup2(pipex.outfile, 1);
	run_command(cmd, pipex);
}

void	child_process(int fds[], t_pipex pipex)
{
	if (pipex.infile < 0)
	{
		ft_putstr_fd("pipex: input: No such file or directory\n", 2);
		exit(0);
	}
	close(fds[0]);
	dup2(fds[1], 1);
	if (pipex.cmd_split != NULL)
		run_command(pipex.cmd, pipex);
}

void	pipes(t_pipex pipex)
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
