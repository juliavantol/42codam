/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 10:21:36 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/22 20:39:48 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* This function finds the last occurence of character c */
/* It returns a pointer to the last occurence of c */
/* It casts the const char str to a char pointer */

char	*ft_strrchr(const char *s, int c)
{
	int		str_len;

	str_len = 0;
	while (s[str_len] != '\0')
		str_len++;
	while (str_len >= 0)
	{
		if (s[str_len] == (char)c)
			return (&((char *) s)[str_len]);
		str_len--;
	}
	return (NULL);
}
