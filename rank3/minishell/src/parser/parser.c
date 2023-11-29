/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 14:25:24 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/29 15:30:26 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	parse_redirection(t_tokens *token, t_cmd *cmd_node)
{
	char	*filename;

	if (token->type == OUTPUT_REDIRECTION || token->type == APPEND_REDIRECTION)
	{
		filename = token->next->value;
		add_redir(&cmd_node->outputs, filename, token->type);
		cmd_node->output_redirection = true;
		return (true);
	}
	else if (token->type == INPUT_REDIRECTION || token->type == HEREDOC)
	{
		filename = token->next->value;
		add_redir(&cmd_node->inputs, filename, token->type);
		cmd_node->input_redirection = true;
		return (true);
	}
	return (false);
}

void	run_parser(t_tokens *tokens)
{
	t_cmd	*commands_list;
	t_cmd	*current_cmd;
	int		index;

	commands_list = NULL;
	index = 0;
	add_command(&commands_list, index);
	current_cmd = last_command(commands_list);
	while (tokens)
	{
		if (parse_redirection(tokens, current_cmd) == true)
			tokens = tokens->next->next;
		if (tokens)
		{
			printf("value: %s\n", tokens->value);
			if (tokens->type == PIPE)
				add_command(&commands_list, index++);
			tokens = tokens->next;
		}
	}
}
