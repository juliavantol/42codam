/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 07:59:55 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/19 12:46:31 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* s1: The string to be trimmed. set: Reference set of characters to trim. */
/* Return : The trimmed string. NULL if the allocation fails. */
/* Allocates with malloc and returns a copy of ’s1’ with the */
/* characters specified in ’set’ removed from the beginning */
/* and the end of the string.*/

int		find_first(char const *s1, char const *set);
int		find_last(char const *s1, char const *set);
char	*make_str(char const *s1, size_t len, size_t start, size_t end);
int	check_empty(char const *s);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	last;
	size_t	first;
	size_t	len;

	if (check_empty(s1))
		return (ft_strdup(""));
	if (ft_strlen(s1) == 0 || !(s1))
		return (ft_strdup(""));

	first = find_first(s1, set);
	last = find_last(s1, set);
	len = (ft_strlen(s1) - ((ft_strlen(s1) - last)) - 1);
	new_str = ft_substr(s1, first, last - first + 1);
	return (new_str);
}

int	check_empty(char const *s)
{
	size_t	count;
	size_t	index;

	count = 0;
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == 32 || (s[index] >= 9 && s[index] <= 13))
			count++;
		index++;
	}
	if (count == index)
		return (1);
	else
		return (0);
}

int	find_first(char const *s1, char const *set)
{
	size_t	index;
	size_t	start;

	index = 0;
	start = 0;
	while (start == index)
	{
		if ((ft_strchr(set, s1[index])))
			start++;
		index++;
	}
	return (start);
}

int	find_last(char const *s1, char const *set)
{
	size_t	index;
	size_t	last;

	index = ft_strlen(s1);
	last = ft_strlen(s1);
	while (last == index)
	{
		if (ft_strchr(set, s1[index]))
			last--;
		index--;
	}
	return (last);
}
