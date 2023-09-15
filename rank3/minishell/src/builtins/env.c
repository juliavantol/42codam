/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 17:37:29 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/15 14:44:08 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	**new_envp(char **old_envp, int size, int skip_index)
{
	char	**new_envp;
	int		index;

	new_envp = ft_calloc(sizeof(char *), size + 1);
	if (!new_envp)
		return (NULL);
	index = 0;
	while (old_envp[index])
	{
		if (skip_index == index && skip_index != -1)
			index++;
		else
		{
			new_envp[index] = ft_strdup(old_envp[index]);
			index++;
		}
	}
	return (new_envp);
}

int	find_envp_entry(t_data *data, char *name)
{
	int	i;
	int	j;

	i = 0;
	while (data->envp[i])
	{
		j = 0;
		while (data->envp[i][j] == name[j])
			j++;
		if (data->envp[i][j] == '=')
			return (i);
		i++;
	}
	return (-1);
}

void	export(t_data *data, char *name, char *value)
{
	int		index;
	char	**envp;
	char	*line;

	index = find_envp_entry(data, name);
	if (index != -1)
		unset(data, name);
	index = 0;
	line = join_three_strs(name, "=", value);
	while (data->envp[index])
		index++;
	if (data->envp)
	{
		envp = new_envp(data->envp, index + 1, -1);
		envp[index++] = ft_strdup(line);
		envp[index] = NULL;
		empty_envp(data);
		data->envp = envp;
	}
}

void	unset(t_data *data, char *name)
{
	int		index;
	int		len;
	char	**envp;

	index = find_envp_entry(data, name);
	if (index == -1)
		return ;
	len = -1;
	while (data->envp[len])
		len++;
	if (data->envp)
	{
		envp = new_envp(data->envp, len + 1, index);
		envp[len] = NULL;
		empty_envp(data);
		data->envp = envp;
	}
}
