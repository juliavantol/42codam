/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 16:31:44 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/16 17:59:54 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	leaks(void)
{
	system("leaks pipex");
}

char	*find_path(char **envp)
{
	int		index;
	char	*path;

	index = 0;
	while (envp[index] != '\0')
	{
		if (ft_strnstr(envp[index], "PATH=", ft_strlen(envp[index])) > 0)
			path = ft_substr(envp[index], 5, ft_strlen(envp[index]));
		index++;
	}
	return (path);
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	char	*command[] = {"grep 'a'", NULL};
	int		fd;
	pid_t	pid;
	int		status;

	if (argc == 5)
	{
		pid = fork();
		if (pid == 0)
		{
			fd = open("Makefile", O_RDONLY);
			dup2(fd, STDIN_FILENO);
			close(fd);
			path = find_path(envp);
			execve(path, command, NULL);
			exit(EXIT_FAILURE);
		}
		wait(&status);
	}
	else
		return (0);
	// leaks();
	argv--;
}
