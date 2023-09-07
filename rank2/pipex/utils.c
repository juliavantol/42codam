/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:29:24 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/23 14:08:50 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_envp(t_pipex *pipex, char **envp)
{
	char	*temp;

	pipex->full_envp = envp;
	if (envp == NULL || envp[0] == NULL)
		pipex->paths = manual_envp();
	else
	{
		while (*envp && !ft_strnstr(*envp, "PATH=", ft_strlen(*envp)))
			envp++;
		temp = ft_substr(*envp, 5, ft_strlen(*envp) - 5);
		if (!temp)
			error_exit("Malloc error");
		pipex->paths = ft_split_paths(temp);
	}
}

char	**manual_envp(void)
{
	char		**paths;
	const char	*temp[] = {"/usr/local/sbin/",
		"/usr/local/bin/", "/usr/sbin/", "/usr/bin/", "/sbin/", "/bin/"};
	int			index;

	index = 0;
	paths = malloc(7 * sizeof(char *));
	if (paths == NULL)
		error_exit("Malloc error");
	while (index < 6)
	{
		paths[index] = ft_strdup(temp[index]);
		if (paths[index] == NULL)
			error_exit("Malloc error");
		index++;
	}
	paths[index] = NULL;
	return (paths);
}

char	*get_cmd_path(char **paths, char	*cmd)
{
	char		*path;
	char		*err;

	cmd = *ft_split(cmd, ' ');
	while (*paths)
	{
		path = ft_strjoin(*paths, cmd);
		if (!path)
			error_exit("Malloc error");
		if (access(path, F_OK) == 0)
			return (free(cmd), path);
		free(path);
		paths++;
	}
	if (access(cmd, F_OK) == 0)
		return (cmd);
	err = ft_strjoin(ft_strjoin("pipex: ", cmd), ": command not found\n");
	if (!err)
		error_exit("Malloc error");
	ft_putstr_fd(err, 2);
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
