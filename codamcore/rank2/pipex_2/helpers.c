/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:29:24 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/27 12:57:53 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

char	**get_paths(char *envp[])
{
	char	*path;

	path = NULL;
	while (*envp++)
	{
		if (ft_strnstr(*envp, "PATH=", ft_strlen(*envp)))
		{
			path = *envp + 5;
			break ;
		}
	}
	return (ft_split_path(path, ':'));
}

int	run_command(char **paths, char *command)
{
	char	*cmd[3];
	char	**split_args = ft_split(command, ' ');

	cmd[1] = command;
	cmd[2] = NULL;
	while (*paths)
	{
		cmd[0] = ft_strjoin(*paths, ft_split(command, ' ')[0]);
		if (access(cmd[0], F_OK) == 0)
			execve(cmd[0], split_args, NULL);
		paths++;
	}
	error_exit("");
	return (0);
}
