/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 13:36:07 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/11 15:01:39 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Return value is the substring. NULL if the allocation fails. 
Allocates (with malloc(3)) and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’. */

char	*ft_substr(char const *s, int start, int len)
{
	int	index;
	char	*sub;

	index = 0;
	if (start >= ft_strlen(s) || ft_strlen(s) == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s) || len < 0)
		sub = (char *)malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else if ((start + len) > ft_strlen(s))
		sub = (char *)malloc(len * sizeof(char));
	else
		sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (index < len && s[start] != '\0')
		sub[index++] = s[start++];
	sub[index] = '\0';
	return (sub);
}
