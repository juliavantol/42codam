/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_splitcopy.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 12:49:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/20 14:46:11 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* s: The string to be split. c: The delimiter character. */
/* Returns: The array of new strings resulting from the split.
NULL if the allocation fails. */
/* Allocates (with malloc(3)) and returns an array of strings 
obtained by splitting ’s’ using the character ’c’ as a delimiter. 
The array must end with a NULL pointer.*/

void	fill_arr(char	**split, char	*word, size_t count);
size_t	get_word(char const *s, size_t i, char c);
size_t	count_words(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*temp_word;
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
			temp_word = ft_substr(s, i, (get_word(s, i, c) - i));
			split[count] = malloc((get_word(s, i, c) - i + 1) * sizeof(char *));
			fill_arr(split, temp_word, count);
			count++;
			i = get_word(s, i, c) ;
		}
	}
	split[count] = 0;
	return (split);
}

void	fill_arr(char	**split, char	*word, size_t count)
{
	int	j;

	j = 0;
	while (word[j] != '\0')
	{
		split[count][j] = word[j];
		j++;
	}
	split[count][j] = '\0';
}

size_t	get_word(char const *s, size_t i, char c)
{
	if (s[i] == c)
		return (0);
	while (s[i] != c)
		i++;
	return (i);
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
			i = get_word(s, i, c);
			count++;
		}
	}
	return (count);
}

// void	empty_arr(char const *s)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while
// }