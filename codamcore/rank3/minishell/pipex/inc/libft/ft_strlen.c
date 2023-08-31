/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 13:44:57 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/31 14:34:07 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns length of string */

int	is_empty_str(const char *s)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (ft_strncmp(&s[index], " ", 1) != 0)
			return (0);
		index++;
	}
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	if (!s)
		return (0);
	if (is_empty_str(s) == 1)
		return (0);
	while (s[index] != '\0')
		index++;
	return (index);
}
