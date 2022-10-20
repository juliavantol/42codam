/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 12:49:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/20 18:50:14 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* s: The string to be split. c: The delimiter character. */
/* Returns: The array of new strings resulting from the split.
NULL if the allocation fails. */
/* Allocates (with malloc(3)) and returns an array of strings 
obtained by splitting ’s’ using the character ’c’ as a delimiter. 
The array must get_word with a NULL pointer.*/

void	fill_arr(char	**split, char	*word, size_t count);
char	*get_word(char const *s, size_t i, char c);
size_t	count_words(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*word;
	size_t	i;
	size_t	count;

	i = 0;
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	count = 0;
	while (i < ft_strlen(s))
	{
		if (get_word(s, i, c) == 0)
			i++;
		else
		{
			word = get_word(s, i, c);
			split[count] = malloc((strlen(word) + 1) * sizeof(char *));
			fill_arr(split, word, count);
			count++;
			i += strlen(word);
		}
	}
	split[count] = 0;
	return (split);
}

void	fill_arr(char	**split, char	*word, size_t count)
{
	int	i;

	i = 0;
	while (word[i] != '\0')
	{
		split[count][i] = word[i];
		i++;
	}
	split[count][i] = '\0';
}

char	*get_word(char const *s, size_t i, char c)
{
	char	*word;
	size_t	index;

	index = i;
	if (s[i] == c)
		return (0);
	while (s[i] != c)
		i++;

	word = ft_substr(s, index, (i - index));
	return (word);
}

size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (i < ft_strlen(s))
	{
		if (get_word(s, i, c) == 0)
			i++;
		else
		{
			i += strlen((get_word(s, i, c)));
			count++;
		}
	}
	return (count);
}