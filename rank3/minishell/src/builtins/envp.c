/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   envp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 17:37:29 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/14 15:12:06 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	**dup_envp(char **envp)
{
	char	**dup_envp;
	int		index;

	index = 0;
	while (envp[index])
		index++;
	dup_envp = ft_calloc(sizeof(char *), index + 1);
	if (!dup_envp)
		return (NULL);
	index = 0;
	while (envp[index])
	{
		dup_envp[index] = ft_strdup(envp[index]);
		if (!dup_envp[index])
			return (NULL);
		index++;
	}
	dup_envp[index] = NULL;
	return (dup_envp);
}

void	empty_envp(t_data *data)
{
	int	index;

	index = 0;
	while (data->envp[index])
	{
		free(data->envp[index]);
		data->envp[index] = NULL;
		index++;
	}
	free(data->envp);
	data->envp = NULL;
}

void	replace_envp(t_data *data, char *line)
{
	int		index;
	char	**new_envp;

	index = 0;
	while (data->envp[index])
		index++;
	if (data->envp)
	{
		new_envp = ft_calloc(sizeof(char *), index + 2);
		if (!new_envp)
			return ;
		index = 0;
		while (data->envp[index])
		{
			new_envp[index] = ft_strdup(data->envp[index]);
			if (!new_envp[index])
				return ;
			index++;
		}
		new_envp[index++] = ft_strdup(line);
		new_envp[index] = NULL;
		empty_envp(data);
		data->envp = new_envp;
	}
}

void	export(t_data *data, char *name, char *value)
{
	char	*line;

	line = ft_strjoin(name, "=");
	if (!line)
		return ;
	line = ft_strjoin(line, value);
	if (!line)
		return ;
	replace_envp(data, line);
}
