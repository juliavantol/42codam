/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 16:31:44 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/20 15:39:37 by juvan-to      ########   odam.nl         */
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
	int		status;
	char	**paths;
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fds) == -1)
		{
			perror("Error with opening the pipe\n");
			return (-1);
		}
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
			wait(&status);
		}	
	}
	else
		return (0);
}
