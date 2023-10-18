/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   envp_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 23:06:59 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/18 23:59:54 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

t_envp	*last_node_envp(t_envp *envp)
{
	t_envp	*temp;

	temp = envp;
	if (envp != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
	}
	return (temp);
}

t_envp	*new_node_envp(char *key, char *value)
{
	t_envp	*node;

	node = malloc(sizeof(t_envp));
	if (node == NULL)
		return (NULL);
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->next = NULL;
	return (node);
}

void	add_node_envp(t_envp **envp, char *key, char *value)
{
	t_envp	*last;
	t_envp	*new;

	new = new_node_envp(key, value);
	if (*envp != NULL && new != NULL)
	{
		last = last_node_envp(*envp);
		last->next = new;
	}
	else
		*envp = new;
}
