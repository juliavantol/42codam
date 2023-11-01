/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export_unset.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 14:27:52 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/01 14:28:09 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	prepare_export(t_exe *executor, t_cmd *command)
{
	char	**split_temp;
	int		index;

	index = 1;
	while (command->split[index])
	{
		split_temp = ft_split(command->split[index], '=');
		export(executor, split_temp[0], split_temp[1]);
		empty_array(split_temp);
		index++;
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
			free(head->value);
			head->value = ft_strdup(value);
			return ;
		}
		head = head->next;
	}
	add_node_envp(&executor->envp_list, key, value);
}

void	unset(t_exe *executor, t_cmd *command)
{
	t_envp	*head;
	t_envp	*prev;

	head = executor->envp_list;
	prev = NULL;
	while (head != NULL)
	{
		if (ft_strcmp(head->key, command->split[1]))
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