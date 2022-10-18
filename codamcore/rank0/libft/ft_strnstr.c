/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 12:08:46 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/17 12:52:02 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This functions locates the first occurrence of the null-terminated */
/* needle in the haystack, no more than len characters are searched. */
/* If needle is an empty string, haystack is returned; if needle occurs */
/* nowhere in haystack, NULL is returned. Otherwise a pointer to the first */
/* character of the first occurrence of needle is returned */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	temp_index;
	int		needle_index;
	int		needle_len;

	needle_len = ft_strlen(needle);
	index = 0;
	needle_index = 0;
	if (needle[0] == '\0')
		return ((char *)&haystack[index]);
	while (haystack[index] != '\0' && index < len)
	{
		needle_index = 0;
		temp_index = index;
		while (haystack[temp_index] == needle[needle_index])
		{
			temp_index++;
			needle_index++;
			if (needle_index == needle_len && (index + needle_index) < len)
				return ((char *)&haystack[index]);
		}
		index++;
	}
	return (NULL);
}
