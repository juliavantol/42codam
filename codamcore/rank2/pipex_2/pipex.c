/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:17:48 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/27 17:20:44 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	leaks(void)
{
	system("leaks pipex");
}

int	main_loop(char *cmd, int fd_in, char **paths)
{
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) == -1)
		error_exit("Error with opening the pipe");
	pid = fork();
	if (pid == -1)
		error_exit("Error with fork");
	if (pid)
	{
		close(fds[1]);
		dup2(fds[0], 0);
	}
	else
	{
		close(fds[0]);
		dup2(fds[1], 1);
		if (fd_in < 0)
			error_exit("Input");
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
	int				status;

	index = 2;
	if (argc < 5)
		error_exit("Not enough arguments");
	path = get_paths(envp);
	pipex.infile = open(argv[1], O_RDONLY);
	dup2(pipex.infile, 0);
	pipex.outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.outfile == -1)
		error_exit("Output");
	dup2(pipex.outfile, 1);
	while (index < argc - 2)
		main_loop(argv[index++], pipex.infile, path);
	run_command(path, argv[index]);
	// waitpid(pid, &status, 0);
	close(pipex.infile);
	close(pipex.outfile);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
