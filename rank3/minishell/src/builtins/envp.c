/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   envp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 17:37:29 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/14 15:32:37 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	**new_envp(char **old_envp, int size)
{
	char	**new_envp;
	int		index;

	new_envp = ft_calloc(sizeof(char *), size + 1);
	if (!new_envp)
		return (NULL);
	while (old_envp[index])
	{
		new_envp[index] = ft_strdup(old_envp[index]);
		if (!new_envp[index])
			return (NULL);
		index++;
	}
	return (new_envp);
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
