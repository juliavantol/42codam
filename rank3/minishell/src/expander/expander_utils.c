/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 23:28:32 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/22 13:56:49 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*find_variable_name(char *str, int index)
{
	char	*key;
	char	*temp;

	temp = ft_strdup(str);
	temp += index;
	index -= 2;
	while (temp[index] && temp[index] != ' ' && temp[index] != '\0'
		&& temp[index] != '"')
		index++;
	temp[index] = '\0';
	key = ft_strdup(temp);
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
