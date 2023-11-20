/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/19 13:47:12 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/20 00:50:04 by Julia         ########   odam.nl         */
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

char	*expand_variable(t_exe *executor, t_cmd *command, char *key)
{
	char	*expanded_command;

	expanded_command = get_variable(executor, key);
	if (expanded_command == NULL)
		expanded_command = ft_strdup("");
	else
	{
		free(command->command_name);
		command->command_name = expanded_command;
	}
	return (expanded_command);
}

// Look for $var, extract var name, replace with value from environment
void	expand_command(t_exe *executor, t_cmd *command)
{
	int	index;

	index = 0;
	while (command->split[index])
	{
		if (command->split[index][0] == '$')
		{
			free(command->split[index]);
			command->split[index] = expand_variable(executor,
					command, command->split[index] + 1);
		}
		index++;
	}
	return ;
}
