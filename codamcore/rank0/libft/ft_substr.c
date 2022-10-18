/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 13:36:07 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/18 15:25:54 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* s: The string from which to create the substring. */
/* start: The start index of the substring in the string ’s’. */
/* len: The maximum length of the substring. */
/* Return value is the substring. NULL if the allocation fails. */
/* Allocates (with malloc(3)) and returns a substring from the string ’s’. */
/* The substring begins at index ’start’ and is of maximum size ’len’.*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*sub;

	index = 0;
	// sub = malloc((len + 1) * sizeof(char));
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL || ft_strlen(s) == 0)
		return (NULL);
	if (start >= ft_strlen(s))
		return ("");
	while (index < len && s[start] != '\0')
	{
		sub[index] = s[start];
		index++;
		start++;
	}
	sub[index] = '\0';
	return (sub);
}
