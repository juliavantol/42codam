/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:29:24 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/01 22:55:33 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd_path(char **paths, char *cmd)
{
	char		*path;

	printf("[%s]", cmd);
	cmd = *ft_split(cmd, ' ');
	while (*paths)
	{
		path = join_str(*paths, cmd);
		if (!path)
			error_exit("Malloc error");
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
		if (!temp)
			error_exit("Malloc error");
		free(split_paths[index]);
		split_paths[index] = temp;
		index++;
	}
	free(whole_str);
	return (split_paths);
}
