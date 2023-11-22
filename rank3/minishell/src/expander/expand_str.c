/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_str.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 22:46:55 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/22 13:57:42 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*expand_string(t_exe *executor, char *input_str)
{
	char	*output;
	char	*temp;
	char	*key;
	char	*variable;
	char	*remainder;
	int		index;

	output = NULL;
	index = needs_expansion(input_str, 0);
	if (index != 0)
	{
		temp = ft_substr(input_str, 0, index - 1);
		key = find_variable_name(input_str, index);
		remainder = ft_substr(input_str, index + ft_strlen(key), ft_strlen(input_str));
		printf("remainder: [%s]\n", remainder);
		variable = get_variable(executor, key);
		output = join_three_strs(temp, variable, remainder);
		free(temp);
		free(key);
	}
	printf("after: [%s]\n", output);
	return (output);
}
