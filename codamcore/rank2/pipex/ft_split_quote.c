/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_quote.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:17:48 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/16 13:01:58 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Returns the array of new strings resulting from the split, NULL if 
the allocation fails. */

/* Frees the array in case of errors */
static void	*free_arr(char	**split, size_t count)
{
	size_t	index;

	index = 0;
	while (index < count)
	{
		free(split[index]);
		index++;
	}
	free(split);
	return (NULL);
}

/* Returns the substring using the starting index of s and its len */
static char	*word(char const *s, unsigned int start, size_t len)
{
	size_t		index;
	char		*sub;

	index = 0;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (index < len && s[start] != '\0')
		sub[index++] = s[start++];
	sub[index] = '\0';
	return (sub);
}

/* Loops through s and fills the array with the found words */
static char	**arr(char const *s, char	**split, size_t count, char c)
{
	size_t	found;
	size_t	start;
	char	*w;

	found = 0;
	start = 0;
	while (s[start])
	{
		while (s[found] != c && s[found] && s[found != '\''] && s[found] != '"')
			found++;
		if (found == start)
			start++;
		else
		{
			w = word(s, start, found - start);
			if (w == NULL)
				return (free_arr(split, count));
			split[count++] = w;
			start = found;
		}
		found = start;
	}
	split[count] = 0;
	return (split);
}

/* Counts how many words can be made after splitting */
static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	index;
	size_t	found;

	found = 0;
	count = 0;
	index = 0;
	while (index < ft_strlen(s))
	{
		while (s[found] != c && s[found])
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
	if (s[index - 1] != c)
		count--;
	return (count);
}

char	**ft_split_quote(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	if (ft_strnstr(s, "'\"", ft_strlen(s)))
		return (delete_sub(s));
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	split = arr(s, split, 0, c);
	return (split);
}
