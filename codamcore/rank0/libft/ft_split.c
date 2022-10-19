/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 12:49:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/19 16:57:42 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* s: The string to be split. c: The delimiter character. */
/* Returns: The array of new strings resulting from the split.
NULL if the allocation fails. */
/* Allocates (with malloc(3)) and returns an array of strings 
obtained by splitting ’s’ using the character ’c’ as a delimiter. 
The array must end with a NULL pointer.*/

size_t	new_index(char const *s, size_t index, char c);
size_t	count_words(char const *s, char c);

// char	**ft_split(char const *s, char c)
// {
// 	char	**split_arr;
// 	char	*temp;
// 	size_t	index;
// 	size_t	index1;
// 	size_t	index3;

// 	split_arr = malloc((count_words(s, c) + 1) * sizeof(char *));
// 	if (!s || !split_arr)
// 		return (0);
// 	index = 0;
// 	temp = "a";
// 	index1 = 0;
// 	index3 = 0;
// 	count_words(s, c);
// 	while (index1 < ft_strlen(s))
// 	{
// 		index1 = new_index(s, index, c);
// 		temp = ft_substr(s, index, (index1 - index));
// 		index = index1;
// 		index++;
// 		split_arr[index3] = temp;
// 		index3++;
// 		printf("%s\n", temp);
// 	}
// 	split_arr = 0;
// 	return (split_arr);
// }

char	**ft_split(char const *s, char c)
{
	char	**split_arr;
	char	*temp;
	size_t	index;

	split_arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split_arr)
		return (0);
	index = 0;
	temp = "a";
	while (index < (count_words(s, c))
	{
		printf("%s\n", temp);
		index++;
	}
	return (split_arr);
}

size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	index;

	count = 0;
	index = 0;
	while (index < ft_strlen(s))
		if (s[index++] == c)
			count++;
	return (count);
}

size_t	new_index(char const *s, size_t index, char c)
{
	while (s[index] != c)
	{
		index++;
	}
	return (index);
}
