/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quotes_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/25 19:21:07 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/25 19:35:03 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

bool	search_substring_from_index(char *stack, char *needle, int index)
{
	int		n_len;
	char	*sub;

	sub = "a";
	if ((stack == NULL || stack[0] == '\0')
		&& ft_strncmp(stack, needle, ft_strlen(needle)) != 0)
		return (false);
	if (needle[0] == '\0' || ft_strlen(needle) <= 0 || ft_strlen(stack) == 0)
		return (false);
	n_len = ft_strlen(needle);
	while (stack[index])
	{
		sub = ft_substr(stack, index, n_len);
		if (ft_strncmp(sub, needle, n_len) == 0)
		{
			free(sub);
			return (true);
		}
		free(sub);
		index++;
	}
	return (false);
}
