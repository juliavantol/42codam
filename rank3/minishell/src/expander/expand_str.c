/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_str.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 22:46:55 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/27 13:40:01 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*expand_str(t_exe *executor, char *str, int index)
{
	char	*temp;
	char	*key;
	char	*variable;
	char	*remainder;

	if (index > 1)
		temp = ft_substr(str, 0, index - 1);
	else
		temp = ft_strdup("");
	key = find_variable_name(str, index);
	remainder = ft_substr(str, index + ft_strlen(key), ft_strlen(str));
	variable = get_variable(executor, key);
	if (!variable)
		variable = ft_strdup("");
	str = join_expanded_str(temp, variable, remainder);
	free(temp);
	free(key);
	free(remainder);
	return (str);
}

void	expand_command(t_exe *executor, t_cmd *command)
{
	char	*temp_output;
	char	*output;
	char	*input;
	int		index;

	input = command->command_name;
	output = ft_strdup(input);
	index = needs_expansion(output, 0, 0);
	while (index != 0)
	{
		temp_output = expand_str(executor, output, index);
		free(output);
		output = temp_output;
		index = needs_expansion(output, 0, 0);
	}
	temp_output = output;
	output = handle_quotes(temp_output, NULL, 0, 0);
	command->command_name = output;
}

void	run_expander(t_exe *executor)
{
	t_cmd	*head;
	char	**cmd_split;

	head = executor->commands_list;
	while (head != NULL)
	{
		expand_command(executor, head);
		cmd_split = ft_split(head->command_name, ' ');
		head->split = cmd_split;
		head = head->next;
	}
}
