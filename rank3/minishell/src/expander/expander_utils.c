/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 23:28:32 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/22 15:32:28 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*find_variable_name(char *str, int index)
{
	char	*key;
	int		end;
	int		start;

	start = index;
	while (str[index] && str[index] != ' ' && str[index] != '\0'
		&& str[index] != '"')
		index++;
	end = ft_strlen(str) - index - 1;
	key = ft_substr(str, start, end);
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
