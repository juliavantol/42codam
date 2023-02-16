/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 13:49:49 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/16 14:10:08 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	char *a[] = {"/usr/bin/grep", "a", NULL};
	pid_t pid;
	int	status;
	int	fd;

	pid = fork();
	if (pid == 0)
	{
		fd = open("Makefile", O_RDONLY);
		dup2(fd, STDIN_FILENO);
		close(fd);
		execve(a[0], a, NULL);
		exit(EXIT_FAILURE);	
	}
	wait(&status);
}

