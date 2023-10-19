/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/19 13:47:12 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/19 11:59:34 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*get_variable(t_exe *executor, char *key)
{
	t_envp	*head;
	char	*exit_code;

	if (ft_strcmp("?", key))
	{
		exit_code = ft_itoa(executor->exit_code);
		return (exit_code);
	}
	head = executor->envp_list;
	while (head != NULL)
	{
		if (ft_strcmp(head->key, key))
			return (head->value);
		head = head->next;
	}
	return (NULL);
}
