/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 16:56:18 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/12/02 14:21:52 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			index;

	p = s;
	index = 0;
	while (index < n)
	{
		p[index] = '\0';
		index++;
	}
}

static void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*m;

	m = malloc(nelem * elsize);
	if (m == NULL)
		return (NULL);
	ft_bzero(m, nelem * elsize);
	return (m);
}

static size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

int	search_newline(char *s)
{
	size_t	index;

	index = 0;
	while (index < ft_strlen(s))
	{
		if (s[index] == '\n')
			return (1);
		index++;
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
	new_str = malloc(sizeof(char) * ft_strlen(stash) + ft_strlen(str) + 1);
	if (!new_str)
		return (NULL);
	while (stash[index])
	{
		new_str[index] = stash[index];
		index++;
	}
	while (str[start])
		new_str[index++] = str[start++];
	new_str[index] = '\0';
	return (new_str);
}

char	*extract_line(char *stash)
{
	size_t	index;
	char	*line;

	printf("stash: %s\n\n", stash);
	printf("end stash\n");
	index = 0;
	line = malloc(ft_strlen(stash) + 1);
	while (index < ft_strlen(stash))
	{
		line[index] = stash[index];
		if (stash[index] == '\n')
			break ;
		index++;
	}
	return (line);
}
