/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:17:48 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/21 17:43:56 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_loop(char **paths, char *cmd)
{
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) == -1)
		error_exit("Pipe error ");
	pid = fork();
	if (pid == -1)
		error_exit("Fork error ");
	if (pid == 0)
	{
		close(fds[0]);
		dup2(fds[1], 1);
		run_command(paths, cmd);
	}
	else
	{
		close(fds[1]);
		wait(NULL);
		dup2(fds[0], 0);
	}
}

int	main_loop(char *cmd, int fd_in, char **paths)
{
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) == -1)
		error_exit("Pipe ");
	pid = fork();
	if (pid == -1)
		error_exit("Fork ");
	if (pid)
	{
		close(fds[1]);
		dup2(fds[0], 0);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(fds[0]);
		dup2(fds[1], 1);
		if (fd_in == 0)
			exit(1);
		else
			run_command(paths, cmd);
	}
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	char			**path;
	struct s_pipex	pipex;
	int				index;

	index = 2;
	if (argc < 5)
		error_exit("");
	path = get_paths(envp);
	pipex.infile = open(argv[1], O_RDONLY);
	pipex.outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	// dup2(pipex.infile, 0);
	// dup2(pipex.outfile, 1);
	// while (index < argc - 1)
	// 	main_loop(argv[index++], pipex.infile, path);
	// dup2(pipex.outfile, 1);
	main_loop(argv[2], pipex.infile, path);
	run_command(path, argv[3]);
	// close(pipex.infile);
	// close(pipex.outfile);
	exit(EXIT_SUCCESS);
}
