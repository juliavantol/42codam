/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_envp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/01 13:19:15 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/18 14:39:09 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	get_envp(t_pipex *pipex, char **envp)
{
	char	*temp;

	pipex->full_envp = envp;
	if (envp == NULL || envp[0] == NULL)
		pipex->paths = manual_envp();
	else
	{
		while (*envp && !ft_strnstr(*envp, "PATH=", 5))
			envp++;
		temp = ft_substr(*envp, 5, ft_strlen(*envp) - 5);
		if (!temp)
			error_exit("ft_malloc error");
		pipex->paths = ft_split_paths(temp);
	}
}

char	**get_paths(char **envp)
{
	char	*paths;
	char	**split_paths;

	while (*envp && !ft_strnstr(*envp, "PATH=", 5))
		envp++;
	paths = ft_substr(*envp, 5, ft_strlen(*envp) - 5);
	if (!paths)
		return (NULL);
	split_paths = ft_split_paths(paths);
	return (split_paths);
}

char	**manual_envp(void)
{
	char		**paths;
	const char	*temp[] = {"/usr/local/sbin/",
		"/usr/local/bin/", "/usr/sbin/", "/usr/bin/", "/sbin/", "/bin/"};
	int			index;

	index = 0;
	paths = ft_malloc(7 * sizeof(char *));
	while (index < 6)
	{
		paths[index] = ft_strdup(temp[index]);
		if (paths[index] == NULL)
			error_exit("ft_malloc error");
		index++;
	}
	paths[index] = NULL;
	return (paths);
}
