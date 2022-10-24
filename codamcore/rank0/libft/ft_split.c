/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 12:49:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/24 11:15:08 by juvan-to      ########   odam.nl         */
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

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*word;
	size_t	i;
	size_t	count;

	i = 0;
	if (!s)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	count = 0;
	while (i < ft_strlen(s))
	{
		word = get_word(s, i, c);
		if (word == 0)
			i++;
		else
		{
			fill_arr(split, word, count);
			i += strlen(word);
			count++;
		}
		free(word);
	}
	split[count] = 0;
	return (split);
}

char	**fill_arr(char	**split, char	*word, size_t count)
{
	size_t	i;

	i = 0;
	split[count] = (char *)malloc(ft_strlen(word) * sizeof(char *));
	if (split[count] == NULL)
		return (NULL);
	while (i < ft_strlen(word))
	{
		split[count][i] = word[i];
		i++;
	}
	split[count][i] = '\0';
	return (split);
}

char	*get_word(char const *s, size_t i, char c)
{
	char	*word;
	size_t	index;

	index = i;
	if (s[i] == c)
		return (0);
	while (s[i] != c && s[i])
		i++;

	word = ft_substr(s, index, (i - index));
	return (word);
}

size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;
	char	*word;

	i = 0;
	count = 0;
	while (i < ft_strlen(s))
	{
		word = get_word(s, i, c);
		if (word == 0)
			i++;
		else
		{
			i += strlen(word);
			count++;
		}
		free(word);
	}
	return (count);
}

// int	main(void)
// {
// 	char	**results;
// 	size_t	index;

// 	results = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
// 	index = 0;
// 	while (results[index] != NULL)
// 	{
// 		printf("%s\n", results[index]);
// 		index++;
// 	}
// }
