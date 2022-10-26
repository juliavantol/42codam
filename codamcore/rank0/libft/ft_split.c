/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 12:49:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/26 11:40:55 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* s: The string to be split. c: The delimiter character. */
/* Returns: The array of new strings resulting from the split.
NULL if the allocation fails. */
/* Allocates (with malloc(3)) and returns an array of strings 
obtained by splitting ’s’ using the character ’c’ as a delimiter. 
The array must end with a NULL pointer.*/

char	**fill_array(char const *s, char	**split, size_t count, char c);
char	*word(char const *s, unsigned int start, size_t len);
void	*free_array(char	**split, size_t count);
size_t	count_words(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	split = fill_array(s, split, 0, c);
	return (split);
}

char	**fill_array(char const *s, char	**split, size_t count, char c)
{
	size_t	found;
	size_t	i;
	char	*w;

	found = 0;
	i = 0;
	while (i < ft_strlen(s))
	{
		while (s[found] != c && s[found])
			found++;
		if (found == i)
			i++;
		else
		{
			w = word(s, i, found - i);
			if (w == NULL)
				return (free_array(split, count));
			split[count++] = w;
			i = found;
		}
		found = i;
	}
	split[count] = 0;
	return (split);
}

char	*word(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*word;

	index = 0;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	while (index < len && s[start] != '\0')
		word[index++] = s[start++];
	word[index] = '\0';
	return (word);
}

size_t	count_words(char const *s, char c)
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
	return (count);
}

void	*free_array(char	**split, size_t count)
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
