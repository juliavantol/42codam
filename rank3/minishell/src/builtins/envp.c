/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   envp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 13:54:40 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/24 13:34:49 by juvan-to      ########   odam.nl         */
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
		free(key);
		free(value);
		i++;
	}
	executor->paths = get_paths(envp);
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

void	export(t_exe *executor, char *key, char *value)
{
	t_envp	*head;

	head = executor->envp_list;
	while (head != NULL)
	{
		if (ft_strcmp(head->key, key))
		{
			head->value = ft_strdup(value);
			return ;
		}
		head = head->next;
	}
	add_node_envp(&executor->envp_list, key, value);
}

void	unset(t_exe *executor, char *key)
{
	t_envp	*head;
	t_envp	*prev;

	head = executor->envp_list;
	prev = NULL;
	while (head != NULL)
	{
		if (ft_strcmp(head->key, key))
		{
			if (prev == NULL)
				executor->envp_list = head->next;
			else
				prev->next = head->next;
			free(head->key);
			free(head->value);
			free(head);
			return ;
		}
		prev = head;
		head = head->next;
	}
}
