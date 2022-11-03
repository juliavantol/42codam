/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 13:36:07 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/03 16:07:58 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Return value is the substring. NULL if the allocation fails. 
Allocates (with malloc(3)) and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’. */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	size_t	j;
	char	*sub;

	index = 0;
	j = 0;
	if (ft_strlen(s) < len || (start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s) || ft_strlen(s) == 0)
		return (ft_strdup(""));
	sub = (char *)malloc(sizeof(*s) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[start] && j < len)
		sub[j++] = s[start++];
	sub[j] = '\0';
	return (sub);
}
