/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 16:31:44 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/20 11:47:02 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	while (*envp++)
	{
		if (ft_strnstr(*envp, "PATH=", ft_strlen(*envp)))
			return (*envp + 5);
	}
	return (0);
}

int	run_command(char **paths, char *command)
{
	int		output;
	char	*cmd[3];
	char	*temp;

	temp = ft_split(command, ' ')[1];
	output = 1;
	cmd[1] = temp;
	cmd[2] = NULL;
	while (*paths)
	{
		cmd[0] = ft_strjoin(*paths, ft_split(command, ' ')[0]);
		output = execve(cmd[0], cmd, NULL);
		if (output != -1)
			return (0);
		paths++;
	}
	return (output);
}
