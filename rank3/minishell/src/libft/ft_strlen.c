/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 13:44:57 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/11 15:01:44 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Returns length of string */

int	is_empty_str(const char *s)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (s[index] != ' ')
			return (0);
		index++;
	}
	return (1);
}

int	ft_strlen(const char *s)
{
	int	index;

	index = 0;
	if (!s)
		return (0);
	if (is_empty_str(s) == 1)
		return (0);
	while (s[index] != '\0')
		index++;
	return (index);
}
