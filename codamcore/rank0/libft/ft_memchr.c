/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 11:27:31 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/13 11:40:30 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			index;

	str = (unsigned char *) s;
	index = 0;
	while (index < n)
	{
		if (str[index] == c)
			return (&str[index]);
		index++;
	}
	return (NULL);
}
