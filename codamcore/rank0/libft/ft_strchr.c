/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 09:54:08 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/22 20:38:51 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function finds the first occurence of character c */
/* It returns a pointer to the first occurence of c */
/* It casts the const char str to a char pointer */

char	*ft_strchr(const char *str, int c)
{
	size_t	index;

	index = 0;
	if (str[index] == (char)c)
		return (&((char *) str)[index]);
	while (index < ft_strlen(str))
	{
		if (str[index] == (char)c)
			return (&((char *) str)[index]);
		if (str[index + 1] == (char)c)
			return (&((char *) str)[index + 1]);
		index++;
	}
	return (NULL);
}
