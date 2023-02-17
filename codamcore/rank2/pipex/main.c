/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 16:31:44 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/18 00:32:26 by Julia         ########   odam.nl         */
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
	path = NULL;
	while (envp[index])
	{
		if (ft_strnstr(envp[index], "PATH=", ft_strlen(envp[index])) > 0)
		{
			path = ft_substr(envp[index], 5, ft_strlen(envp[index]));
			break;
		}
		index++;
	}
	return (path);
}

void loop_paths(char *path)
{
	int		index;
	int		start;
	char	*str;

	index = 0;
	start = 0;
	while (path[index])
	{
		if (path[index] == ':')
		{
			str = ft_substr(path, start, index - start);
			printf("%s\n\n", str);
			start = index + 1;
		}
		index++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	char	*command[] = {"/usr/bin/grep", "a", NULL};
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
			path = ft_strjoin(path, "/grep");
			printf("%s\n\n\n", path);
			loop_paths(path);
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
