/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 16:31:44 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/19 18:44:37 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	leaks(void)
{
	system("leaks pipex");
}


int	main(int argc, char **argv, char **envp)
{
	char	*path;
	int		fd;
	pid_t	pid;
	int		status;
	char	**split_path;

	if (argc == 5)
	{
		path = find_path(envp);
		split_path = ft_split_path(path, ':');
		pid = fork();
		if (pid == 0)
		{
			fd = open("Makefile", O_RDONLY);
			dup2(fd, STDIN_FILENO);
			close(fd);
			if (loop_paths(split_path, "ls -l") == -1)
				printf("Command couldn't be executed\n");
			exit(EXIT_FAILURE);
		}
		wait(&status);
	}
	else
		return (0);
	// leaks();
	argv--;
}
