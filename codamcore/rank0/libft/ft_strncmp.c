/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 10:35:36 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/18 11:19:36 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function compares no more than n bytes */
/* It returns 0 if equal, < 0 if str1 < s2 */
/* and > 0 if str2 < s1 */
/* The function also typecasts the difference to unsigned char */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;
	int		r;

	index = 0;
	r = 0;
	while (index < n && (*(s1 + index) || *(s2 + index)))
	{
		if (*(s1 + index) != *(s2 + index))
		{
			r = *((unsigned char *)s1 + index) - *((unsigned char *)s2 + index);
			break ;
		}
		index++;
	}
	return (r);
}
