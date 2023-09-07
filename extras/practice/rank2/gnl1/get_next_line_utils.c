/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 00:40:43 by Julia         #+#    #+#                 */
/*   Updated: 2023/02/09 00:50:01 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

int	search_newline(char	*str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
	{
		if (str[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

char	*ft_calloc(size_t nelem, size_t nsize)
{
	size_t	index;
	char	*str;

	index = 0;
	str = malloc(nelem * nsize);
	if (!str)
		return (NULL);
	while (index < nelem * nsize)
		str[index++] = '\0';
	return (str);
}

char	*ft_strjoin(char	*stash, char	*line, int index, int start)
{
	char	*str;

	if (!stash)
	{
		stash = ft_calloc(1, 1);
		if (!stash)
			return (NULL);
	}
	str = ft_calloc(ft_strlen(stash) + ft_strlen(line) + 1, sizeof(char));
	if (!str)
		return (free(stash), free(line), NULL);
	while (stash[index])
	{
		str[index] = stash[index];
		index++;
	}
	while (line[start])
		str[index++] = line[start++];
	str[index] = '\0';
	free(stash);
	return (str);
}
