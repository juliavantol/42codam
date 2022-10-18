/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 09:54:08 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/17 12:09:29 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* This function finds the first occurence of character c */
/* It returns a pointer to the first occurence of c */
/* It casts the const char str to a char pointer */

char	*ft_strchr(const char *str, int c)
{
	int		index;

	index = 0;
	if (str[index] == c)
		return (&((char *) str)[index]);
	while (str[index] != '\0')
	{
		if (str[index] == c)
			return (&((char *) str)[index]);
		if (str[index + 1] == c)
			return (&((char *) str)[index + 1]);
		index++;
	}
	return (NULL);
}
