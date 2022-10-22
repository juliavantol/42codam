/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 12:08:46 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/22 22:59:02 by Julia         ########   odam.nl         */
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
	size_t	needle_len;
	char	*sub;

	index = 0;
	// hou deze boven
	if ((haystack == NULL || haystack[0] == '\0') && ft_strncmp(haystack, needle, ft_strlen(needle)) != 0)
	{
		// printf("1\n");
		return (NULL);
	}
	if (needle[0] == '\0' || ft_strlen(needle) <= 0 || ft_strlen(haystack) == 0)
	{
		// printf("2\n");
		return ((char *)haystack);
	}
	needle_len = ft_strlen(needle);
	while (index < ft_strlen(haystack) && index < len && (index + needle_len - 1) < len)
	{
		sub = ft_substr(haystack, index, needle_len);
		if (ft_strncmp(sub, needle, needle_len) == 0)
			return ((char *)&haystack[index]);
		index++;
	}
	return (NULL);
}
