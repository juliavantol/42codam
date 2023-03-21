/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_pipex.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 13:59:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/21 14:38:56 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	count_words(char const *s)
{
	size_t	count;
	size_t	index;
	size_t	found;

	found = 0;
	count = 0;
	index = 0;
	while (index < ft_strlen(s))
	{
		while (s[found] != ' ' && s[found])
			found++;
		if (found == index)
			index++;
		else
		{
			index = found;
			count++;
		}
		found = index;
	}
	return (count);
}

static char	*make_word(char const *s, size_t index, size_t len)
{
	size_t	start;
	char	*word;

	start = index;
	if (s[index] == '\'' || s[index] == '"')
	{
		index++;
		while (s[index + len] != s[start] && s[index + len])
			len++;
		if (!s[index + len])
			len = 0;
		start = index;
	}
	else
	{
		while (s[index] != ' ' && s[index])
		{
			index++;
			len++;
		}
	}
	word = ft_substr(s, start, len);
	if (!word)
		error_exit("Malloc error");
	return (word);
}

static char	**ft_fill(char const *s, char **split)
{
	size_t	index;
	size_t	count;
	char	*word;

	index = 0;
	count = 0;
	while (s[index])
	{
		while (s[index] == ' ' && s[index])
			index++;
		word = make_word(s, index, 0);
		if (ft_strlen(word) != 0)
			split[count++] = word;
		index += ft_strlen(word) + 1;
	}
	split[count] = NULL;
	return (split);
}

char	**ft_split_pipex(char const *s)
{
	char	**split;

	split = malloc((count_words(s) + 1) * sizeof(char *));
	if (split == NULL)
		error_exit("Malloc error");
	ft_fill(s, split);
	return (split);
}
