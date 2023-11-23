/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_str.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 22:46:55 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/23 13:57:48 by juvan-to      ########   odam.nl         */
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

bool	is_str_enclosed_by_quotes(char *str, char quote)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	if (len < 2)
		return (false);
	if (str[0] != quote || str[len - 1] != quote)
		return (false);
	while (i < len - 1)
	{
		if (str[i] == quote && str[i + 1] != quote)
			return (true);
		i++;
	}
	return (false);
}

char	*start_expander(t_exe *executor, char *input)
{
	char	*temp_output;
	char	*output;
	int		index;

	output = ft_strdup(input);
	index = needs_expansion(output, 0);
	while (index != 0)
	{
		temp_output = expand_str(executor, output, index);
		free(output);
		output = temp_output;
		index = needs_expansion(output, 0);
	}
	// handle_quotes(output);
	remove_quotes(output, '\'', 0, 0);
	remove_quotes(output, '"', 0, 0);
	printf("after: [%s]\n", output);
	return (output);
}
