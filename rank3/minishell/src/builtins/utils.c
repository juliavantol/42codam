/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/15 02:06:06 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/15 15:08:40 by juvan-to      ########   odam.nl         */
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

char	*join_three_strs(char *s1, char *s2, char *s3)
{
	int		i;
	int		j;
	char	*output;

	i = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	output = ft_malloc(sizeof(char) * (i + 1));
	i = 0;
	j = 0;
	while (s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	while (s2[j])
		output[i++] = s2[j++];
	j = 0;
	while (s3[j])
		output[i++] = s3[j++];
	output[i] = '\0';
	return (output);
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
