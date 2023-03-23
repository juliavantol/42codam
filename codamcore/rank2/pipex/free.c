/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 12:49:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/23 13:39:20 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmd_split(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_split[i])
	{
		free(pipex->cmd_split[i]);
		i++;
	}
	free(pipex->cmd_split);
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
		temp = ft_strjoin(split_paths[index], "/");
		if (!temp)
			error_exit("Malloc error");
		free(split_paths[index]);
		split_paths[index] = temp;
		index++;
	}
	free(whole_str);
	return (split_paths);
}
