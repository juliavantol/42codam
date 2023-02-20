/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 16:31:44 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/20 12:20:02 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	leaks(void)
{
	system("leaks pipex");
}

int	main(int argc, char **argv, char **envp)
{
	int		fd;
	int		fds[2];
	pid_t	pid;
	int		status;
	char	**paths;

	if (argc == 5)
	{
		paths = ft_split_path(get_path(envp), ':');
		pid = fork();
		if (pid == 0)
		{
			fd = open(argv[1], O_RDONLY);
			dup2(fd, STDIN_FILENO);
			close(fd);
			if (run_command(paths, argv[2]) == -1)
				printf("Command couldn't be executed\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("\ntweede\n");
		}
		wait(&status);
	}
	else
		return (0);
	argv--;
}
