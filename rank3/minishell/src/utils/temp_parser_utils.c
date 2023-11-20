/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   temp_parser_utils.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 13:05:23 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/20 12:36:40 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

t_cmd	*last_command_node(t_cmd *command)
{
	t_cmd	*temp;

	temp = command;
	if (command != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
	}
	return (temp);
}

t_cmd	*new_command_node(char *command_line_split, int index)
{
	t_cmd	*node;

	node = ft_malloc(sizeof(t_cmd));
	node->command_name = ft_strdup("");
	node->outputs = NULL;
	node->inputs = NULL;
	node->output_redirection = false;
	node->input_redirection = false;
	node->index = index;
	divide_command_in_redirections(node, command_line_split, 0);
	node->split = ft_split(node->command_name, ' ');
	node->next = NULL;
	return (node);
}

void	add_command_node(t_cmd **commands, char *command_line_split, int index)
{
	t_cmd	*last;
	t_cmd	*new;

	new = new_command_node(command_line_split, index);
	if (*commands != NULL && new != NULL)
	{
		last = last_command_node(*commands);
		last->next = new;
	}
	else
		*commands = new;
}
