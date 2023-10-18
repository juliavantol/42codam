/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   envp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 13:54:40 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/19 00:12:29 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	init_envp(t_exe *executor, char **envp)
{
	int		i;
	int		j;
	char	*key;
	char	*value;

	i = 0;
	executor->envp_list = NULL;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] != '=')
			j++;
		key = ft_substr(envp[i], 0, j);
		value = ft_substr(envp[i], j + 1, ft_strlen(envp[i]) - j);
		add_node_envp(&executor->envp_list, key, value);
		i++;
	}
}

void	print_env(t_exe *executor)
{
	t_envp	*head;

	head = executor->envp_list;
	while (head != NULL)
	{
		printf("%s=%s\n", head->key, head->value);
		head = head->next;
	}
}
