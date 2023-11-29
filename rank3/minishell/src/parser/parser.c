/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 14:25:24 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/29 15:18:04 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	parse_redirection(t_tokens *token)
{
	if (token->type == INPUT_REDIRECTION || token->type == OUTPUT_REDIRECTION
		|| token->type == APPEND_REDIRECTION || token->type == HEREDOC)
	{
		printf("%d\n", token->type);
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
		parse_redirection(tokens);
		if (tokens->type == PIPE)
			add_command(&commands_list, index++);
		tokens = tokens->next;
	}
}
