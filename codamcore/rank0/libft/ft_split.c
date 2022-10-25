/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 12:49:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/25 15:26:46 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* s: The string to be split. c: The delimiter character. */
/* Returns: The array of new strings resulting from the split.
NULL if the allocation fails. */
/* Allocates (with malloc(3)) and returns an array of strings 
obtained by splitting ’s’ using the character ’c’ as a delimiter. 
The array must end with a NULL pointer.*/

char	**fill_arr(char	**split, char	*word, size_t count);
char	*get_word(char const *s, size_t i, char c);
size_t	count_words(char const *s, char c);

// char	**ft_split(char const *s, char c)
// {
// 	char	**split;
// 	char	*word;
// 	size_t	i;
// 	size_t	count;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	split = malloc((count_words(s, c) + 1) * sizeof(char *));
// 	if (split == NULL)
// 		return (NULL);
// 	count = 0;
// 	while (i < ft_strlen(s))
// 	{
// 		word = get_word(s, i, c);
// 		if (word == 0)
// 			i++;
// 		else
// 		{
// 			fill_arr(split, word, count);
// 			i += strlen(word);
// 			count++;
// 		}
// 		free(word);
// 	}
// 	split[count] = 0;
// 	return (split);
// }

// char	**fill_arr(char	**split, char	*word, size_t count)
// {
// 	size_t	i;

// 	i = 0;
// 	split[count] = (char *)malloc(ft_strlen(word) + 1);
// 	if (split[count] == NULL)
// 		return (NULL);
// 	while (i < ft_strlen(word))
// 	{
// 		split[count][i] = word[i];
// 		i++;
// 	}
// 	split[count][i] = '\0';
// 	return (split);
// }

// char	*get_word(char const *s, size_t i, char c)
// {
// 	char	*word;
// 	size_t	index;

// 	index = i;
// 	if (s[i] == c)
// 		return (0);
// 	while (s[i] != c && s[i])
// 		i++;
// 	word = ft_substr(s, index, (i - index));
// 	return (word);
// }

// size_t	count_words(char const *s, char c)
// {
// 	size_t	count;
// 	size_t	i;
// 	char	*word;

// 	i = 0;
// 	count = 0;
// 	while (i < ft_strlen(s))
// 	{
// 		word = get_word(s, i, c);
// 		if (word == 0)
// 			i++;
// 		else
// 		{
// 			i += strlen(word);
// 			count++;
// 		}
// 		free(word);
// 	}
// 	return (count);
// }

char	**fill_arr(char	**split, char	*word, size_t count);
char	*get_word(char const *s, size_t i, char c);
size_t	count_words(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	count;

	if (!s)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	count = count_words(s, c);
	printf("%zu\n", count);
	// while (i < ft_strlen(s))
	// {
	// 	word = get_word(s, i, c);
	// 	if (word == 0)
	// 		i++;
	// 	else
	// 	{
	// 		fill_arr(split, word, count);
	// 		i += strlen(word);
	// 		count++;
	// 	}
	// 	free(word);
	// }
	// split[count] = 0;
	return (split);
}

// char	**fill_arr(char	**split, char	*word, size_t count)
// {
// 	size_t	i;

// 	i = 0;
// 	split[count] = (char *)malloc(ft_strlen(word) + 1);
// 	if (split[count] == NULL)
// 		return (NULL);
// 	while (i < ft_strlen(word))
// 	{
// 		split[count][i] = word[i];
// 		i++;
// 	}
// 	split[count][i] = '\0';
// 	return (split);
// }

size_t	count_words(char const *s, char c)
{
	size_t	count;
	char	*copy;
	char	*last;

	count = 0;
	copy = (char *)s;
	last = 0;
	while (*copy)
	{
		if (*copy == c)
		{
			last = copy;
			count++;
		}
		copy++;
	}
	return (count);
}
