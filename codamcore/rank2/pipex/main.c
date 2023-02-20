/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 16:31:44 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/20 17:36:13 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main_loop(char *cmd, int fd_in, char **paths)
{
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) == -1)
		error_exit("Error with opening the pipe\n");
	pid = fork();
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
			return (run_command(paths, cmd));
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	int		fd_in;
	int		fd_out;

	if (argc == 5)
	{
		paths = ft_split_path(get_path(envp), ':');
		fd_in = open(argv[1], O_RDONLY);
		fd_out = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd_out < 0)
			error_exit("Outfile");
		dup2(fd_in, 0);
		dup2(fd_out, 1);
		main_loop(argv[2], fd_in, paths);
		run_command(paths, argv[3]);
	}
	else
		error_exit("Not enough parameters\n");
	return (0);
}
