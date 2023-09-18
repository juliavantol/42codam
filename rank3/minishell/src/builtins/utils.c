/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/15 02:06:06 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/18 13:58:53 by juvan-to      ########   odam.nl         */
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

int	find_envp_entry(t_executor *executor, char *name)
{
	int	i;
	int	j;

	i = 0;
	while (executor->minishell_envp[i])
	{
		j = 0;
		while (executor->minishell_envp[i][j] == name[j])
			j++;
		if (executor->minishell_envp[i][j] == '=')
			return (i);
		i++;
	}
	return (-1);
}

void	empty_envp(t_executor *executor)
{
	int	index;

	index = 0;
	while (executor->minishell_envp[index])
	{
		free(executor->minishell_envp[index]);
		executor->minishell_envp[index] = NULL;
		index++;
	}
	free(executor->minishell_envp);
	executor->minishell_envp = NULL;
}
