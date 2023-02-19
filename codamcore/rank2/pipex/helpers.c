/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 16:31:44 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/19 23:22:16 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	while (*envp++)
	{
		if (ft_strnstr(*envp, "PATH=", ft_strlen(*envp)))
			return(*envp + 5);
	}
	return (0);
}

int	loop_paths(char **paths, char *command)
{
	int		output;
	char	*a[3];
	char	*temp;

	temp = ft_split(command, ' ')[0];
	output = 1;
	a[1] = command;
	a[2] = NULL;
	
	while (*paths)
	{
		a[0] = *paths;
		output = execve(ft_strjoin(*paths, temp), a, NULL);
		if (output != -1)
			return (0);
		paths++;
	}
	return (output);
}
