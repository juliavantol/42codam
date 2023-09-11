/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 16:56:18 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/11 15:03:58 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	search_newline(char *s)
{
	size_t	index;

	index = 0;
	if (!s)
		return (0);
	while (index < ft_strlen(s))
	{
		if (s[index++] == '\n')
			return (1);
	}
	return (0);
}

char	*ft_strjoin(char *stash, char *str, size_t index, size_t start)
{
	char	*new_str;

	if (!stash)
	{
		stash = ft_calloc(1, 1);
		if (stash == NULL)
			return (NULL);
	}
	new_str = ft_calloc(ft_strlen(stash) + ft_strlen(str) + 1, sizeof(char));
	if (!new_str)
		return (free(stash), NULL);
	while (stash[index])
	{
		new_str[index] = stash[index];
		index++;
	}
	while (str[start])
		new_str[index++] = str[start++];
	new_str[index] = '\0';
	free(stash);
	return (new_str);
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*str;
	size_t	index;

	str = malloc(nelem * elsize);
	if (str == NULL)
		return (NULL);
	index = 0;
	while (index < nelem * elsize)
		str[index++] = '\0';
	return (str);
}
