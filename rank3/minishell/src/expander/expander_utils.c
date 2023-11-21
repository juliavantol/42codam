/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 23:28:32 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/22 00:05:24 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

bool	needs_expansion(char *str, int index)
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
		return (false);
	if (str[index + 1] == '\0')
		return (false);
	if (str[index - 1] == '\'')
		return (false);
	return (true);
}
