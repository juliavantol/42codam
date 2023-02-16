/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   practice.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 17:16:33 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/16 17:37:35 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// fd[0] == read
// fd[1] == write

int	pipex(int stdin, int stdout, char *cmd1, char *cmd2)
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
		close(stdin);
		str = "Hello!\n";
		write(stdout, str, ft_strlen(str));
		close(stdout);
	}
	else
	{
		close(stdout);
		read(stdin, &test, sizeof(int));
		close(stdin);
	}
	cmd1--;
	cmd2--;
	return (0);
}

int	main(int argc, char **argv)
{
	int	stdin;
	int	stdout;

	if (argc == 5)
	{
		stdin = open(argv[1], O_RDONLY);
		stdout = open(argv[4], O_CREAT | O_RDWR | O_TRUNC);
		if (stdin == -1 || stdout == -1)
		{
			perror("Error with opening file");
			return (-1);
		}
		pipex(stdin, stdout, argv[2], argv[4]);
		close(stdin);
		close(stdout);
	}
	else
		return (0);
}
