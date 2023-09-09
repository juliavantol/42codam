/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:29:24 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/08 12:19:31 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	if (!s1 || !s2)
		return (false);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	while (s1[index] && s2[index])
	{
		if (s1[index] != s2[index])
			return (false);
		index++;
	}
	return (true);
}

int	check_input(char **argv, int argc)
{
	if (argc < 5)
	{
		ft_putstr_fd("Not enough arguments\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (argv[1])
	{
		if (ft_strcmp(argv[1], "here_doc") == true)
			return (1);
	}
	return (0);
}

char	*get_cmd_path(char **paths, char *cmd)
{
	char		*path;

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
