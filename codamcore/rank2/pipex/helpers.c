/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:29:24 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/02 13:37:38 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *msg)
{
	perror(msg);
	exit(errno);
}

char	*get_cmd_path(char *envp[], char	*cmd)
{
	char	*path;
	char	**all_paths;

	while (*envp && !ft_strnstr(*envp, "PATH=", ft_strlen(*envp)))
		envp++;
	all_paths = ft_split_path(ft_substr(*envp, 5, ft_strlen(*envp) - 5), ':');
	cmd = *ft_split_quote(cmd, ' ');
	while (*all_paths)
	{
		path = ft_strjoin(*all_paths, cmd);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		all_paths++;
	}
	if (access(cmd, F_OK) == 0)
		return (cmd);
	ft_putstr_fd("Command not found\n", 2);
	exit(127);
	return (NULL);
}
