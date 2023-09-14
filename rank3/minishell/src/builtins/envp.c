/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   envp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 17:37:29 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/14 12:59:48 by juvan-to      ########   odam.nl         */
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
		if (!dup_envp)
			return (NULL);
		index++;
	}
	dup_envp[index] = NULL;
	return (dup_envp);
}

void	env(t_data *data)
{
	int	index;

	index = 0;
	while (data->envp[index])
		printf("%s\n", data->envp[index++]);
}
