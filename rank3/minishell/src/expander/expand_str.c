/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_str.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 22:46:55 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/26 00:23:43 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

// echo $USER lalala $PWD

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

void	leaks(void)
{
	system("leaks -s minishell");
}

char	*start_expander(t_exe *executor, t_cmd *command)
{
	char	*temp_output;
	char	*output;
	char	*input;
	int		index;

	// atexit(leaks);
	input = command->command_name;
	output = ft_strdup(input);
	index = needs_expansion(output, 0);
	while (index != 0)
	{
		temp_output = expand_str(executor, output, index);
		free(output);
		output = temp_output;
		index = needs_expansion(output, 0);
	}
	handle_quotes(output, NULL);
	// remove_quotes(output, '\'', 0, 0);
	// remove_quotes(output, '"', 0, 0);
	command->command_name = output;
	//printf("after: [%s]\n", command->command_name);
	exit(1);
	return (output);
}
