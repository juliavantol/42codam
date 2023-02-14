/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 16:31:44 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/14 14:05:36 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// fd[0] == read
// fd[1] == write

int	pipex(char *stdin, char *stdout, char *cmd1, char *cmd2)
{
	int		fd[2];
	int		id;
	char	*str;
	int		test;

	if (pipe(fd) == -1)
	{
		perror("An error ocurred with opening the pipe\n");
		return (0);
	}
	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		str = "Hello!\n";
		write(fd[1], str, ft_strlen(str));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		read(fd[0], &test, sizeof(int));
		close(fd[0]);
	}
	printf("%s %s %s %s\n", stdin, cmd1, stdout, cmd2);
	return (0);
}

int	main(int argc, char **argv)
{
	int		len;

	if (argc == 5)
	{
		pipex(argv[1], argv[3], argv[2], argv[4]);
	}
	else
	{
		len = ft_strlen("heyyy!");
		ft_printf("%d\n", len);
		return (0);
	}
}
