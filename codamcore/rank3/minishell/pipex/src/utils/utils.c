/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:29:24 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/05 14:27:00 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_input(char **argv, int argc)
{
	if (argv[1])
	{
		printf("1: %s\n", argv[1]);
	}
	if (argc < 5)
	{
		ft_putstr_fd("Not enough arguments\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

char	*get_cmd_path(char **paths, char *cmd)
{
	char		*path;

	printf("[%s]", cmd);
	cmd = *ft_split(cmd, ' ');
	while (*paths)
	{
		path = join_str(*paths, cmd);
		if (access(path, F_OK) == 0)
			return (free(cmd), path);
		free(path);
		paths++;
	}
	if (access(cmd, F_OK) == 0)
		return (cmd);
	cmd_error(cmd);
	exit(127);
	return (NULL);
}

char	**ft_split_paths(char *whole_str)
{
	char	**split_paths;
	int		index;
	char	*temp;

	index = 0;
	split_paths = ft_split(whole_str, ':');
	if (!split_paths)
		error_exit("Malloc error");
	while (split_paths[index])
	{
		temp = join_str(split_paths[index], "/");
		free(split_paths[index]);
		split_paths[index] = temp;
		index++;
	}
	free(whole_str);
	return (split_paths);
}
