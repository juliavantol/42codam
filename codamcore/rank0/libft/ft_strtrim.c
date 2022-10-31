/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 07:59:55 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/31 17:58:48 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates with malloc and returns a copy of ’s1’ with the characters 
specified in ’set’ removed from the beginning and the end of the string. */

static int	find_first(char const *s1, char const *set);
static int	find_last(char const *s1, char const *set);
static int	check_set(char const *set, char c);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	last;
	size_t	first;

	if (!s1)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	first = find_first(s1, set);
	last = find_last(s1, set);
	new_str = ft_substr(s1, first, last - first + 1);
	return (new_str);
}

static int	check_set(char const *set, char c)
{
	size_t	index;

	index = 0;
	while (set[index] != '\0')
	{
		if (set[index] == c)
			return (1);
		index++;
	}
	return (0);
}

static int	find_first(char const *s1, char const *set)
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

static int	find_last(char const *s1, char const *set)
{
	size_t	index;
	size_t	last;

	index = ft_strlen(s1);
	last = ft_strlen(s1);
	while (last == index)
	{
		if (ft_strchr(set, s1[index--]))
			last--;
	}
	return (last);
}
