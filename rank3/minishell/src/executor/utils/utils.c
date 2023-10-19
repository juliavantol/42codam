/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:29:24 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/19 11:57:32 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

char	*get_cmd_path(char **paths, char *cmd)
{
	int		index;
	char	*path;

	index = 0;
	while (paths[index])
	{
		path = join_three_strs(paths[index], NULL, cmd);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		index++;
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
		temp = join_three_strs(split_paths[index], NULL, "/");
		free(split_paths[index]);
		split_paths[index] = temp;
		index++;
	}
	split_paths[index] = NULL;
	free(whole_str);
	return (split_paths);
}
