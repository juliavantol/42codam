/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 21:07:31 by Julia         #+#    #+#                 */
/*   Updated: 2023/02/09 00:50:23 by Julia         ########   odam.nl         */
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

int	find_newline(char *str)
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

char	*ft_strjoin(char *stash, char *line, int index, int start)
{
	char	*new_str;

	if (!stash)
	{
		stash = ft_calloc(1, 1);
		if (!stash)
			return (NULL);
	}
	new_str = ft_calloc(ft_strlen(stash) + ft_strlen(line) + 1, sizeof(char));
	if (!new_str)
		return (free(line), free(stash), NULL);
	while (stash[index])
	{
		new_str[index] = stash[index];
		index++;
	}
	while (line[start])
		new_str[index++] = line[start++];
	new_str[index] = '\0';
	free(stash);
	return (new_str);
}

void	*ft_calloc(size_t	nelem, size_t	nsize)
{
	char	*str;
	size_t	index;

	str = malloc(nelem * nsize);
	if (!str)
		return (NULL);
	index = 0;
	while (index < nelem * nsize)
		str[index++] = '\0';
	return (str);
}
