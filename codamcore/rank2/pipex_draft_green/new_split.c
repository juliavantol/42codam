/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_split.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 18:00:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/20 18:34:41 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

size_t	count_words(char const *s)
{
	size_t	count;
	size_t	index;

	count = 0;
	index = 0;
	while (index < ft_strlen(s))
	{
		if (s[index] == ' ')
			count++;
		index++;
	}
	return (count);
}

char	**ft_split_pipex(char const *s)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((count_words(s) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	return (split);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("%zu\n", count_words(argv[1]));	
	}
}
