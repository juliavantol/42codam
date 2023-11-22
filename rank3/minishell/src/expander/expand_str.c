/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_str.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 22:46:55 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/22 14:56:34 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*start_expander(t_exe *executor, char *input, char *output, int index)
{
	char	*temp;
	char	*key;
	char	*variable;
	char	*remainder;

	temp = ft_substr(input, 0, index - 1);
	key = find_variable_name(input, index);
	remainder = ft_substr(input, index + ft_strlen(key), ft_strlen(input));
	variable = get_variable(executor, key);
	output = join_three_strs(temp, variable, remainder);
	free(temp);
	free(key);
	free(remainder);
	return (output);
}

char	*expand_string(t_exe *executor, char *input)
{
	char	*output;
	int		index;

	output = NULL;
	index = needs_expansion(input, 0);
	if (index == 0)
		output = ft_strdup(input);
	else
		output = start_expander(executor, input, output, index);
	printf("after: [%s]\n", output);
	return (output);
}
