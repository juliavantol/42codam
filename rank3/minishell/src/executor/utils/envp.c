/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   envp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/01 13:19:15 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/09 22:59:27 by Julia         ########   odam.nl         */
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
