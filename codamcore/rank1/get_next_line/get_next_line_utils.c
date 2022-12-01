/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 16:56:18 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/12/02 00:34:08 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

char	*add_to_stash(char *stash, char *str)
{
	char	*new_str;
	size_t	str_len;
	int		index;
	int		second;

	str_len = ft_strlen(stash) + ft_strlen(str);
	new_str = (char *)malloc((str_len + 1) * sizeof(char));
	index = 0;
	if (new_str == NULL)
		return (NULL);
	while (stash[index] != '\0')
	{
		new_str[index] = stash[index];
		index++;
	}
	second = index;
	index = 0;
	while (str[index] != '\0')
		new_str[second++] = str[index++];
	new_str[second] = '\0';
	return (new_str);
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

char	*extract_line(char *stash)
{
	size_t	index;
	char	*line;

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

char	*empty_stash(char *stash)
{
	// size_t	index;

	// index = 0;
	// while (index < ft_strlen(stash))
	// {
	// 	stash[index] = '\0';
	// 	if (stash[index] == '\n')
	// 		break ;
	// 	index++;
	// }
	// printf("stash: %s\n", stash);
	return (stash);
}

char	*ft_strjoin(char **stash, char *str)
{
	char	*new_str;
	size_t	str_len;
	size_t	index;

	if (!*stash)
		*stash = "hello";
	str_len = ft_strlen(*stash) + ft_strlen(str);
	new_str = (char *)malloc((str_len + 4) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	index = 0;
	while (index < ft_strlen(*stash))
	{
		new_str[index] = 'a';
		index++;
	}
	new_str[index] = **stash;
	new_str[index] = **stash;
	return (new_str);
}
