/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 23:28:32 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/22 15:45:06 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*find_variable_name(char *str, int index)
{
	char	*key;
	int		start;
	int		len;

	start = index;
	len = 0;
	while (str[index] && str[index] != ' ' && str[index] != '\0'
		&& str[index] != '"')
	{
		len++;
		index++;
	}
	key = ft_substr(str, start, len);
	return (key);
}

int	needs_expansion(char *str, int index)
{
	int	start_position;

	start_position = 0;
	while (str[index])
	{
		if (str[index] == '$')
		{
			start_position = index + 1;
			break ;
		}
		index++;
	}
	if (index == ft_strlen(str))
		return (0);
	if (str[index + 1] == '\0')
		return (0);
	if (str[index - 1] == '\'')
		return (0);
	return (start_position);
}
