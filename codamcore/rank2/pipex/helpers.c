/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:29:24 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/28 12:33:07 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *msg)
{
	perror(msg);
	if (ft_strncmp(msg, "Command not found", 19) == 0)
		exit(127);
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

void	run_command(char **paths, char *command)
{
	char	*cmd[3];
	char	**split_args;
	int		output;

	if (ft_strrchr(command, '/') != 0)
		command = ft_strrchr(command, '/');
	split_args = ft_split(command, ' ');
	cmd[1] = command;
	cmd[2] = NULL;
	while (*paths)
	{
		cmd[0] = ft_strjoin(*paths, ft_split(command, ' ')[0]);
		if (access(cmd[0], F_OK) == 0)
		{
			output = execve(cmd[0], split_args, NULL);
			free(cmd[0]);
			if (output < 0)
				error_exit("Execve error failed");
		}
		paths++;
	}
	free(cmd[0]);
	error_exit("Command not found");
}
