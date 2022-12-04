/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/03 14:16:08 by Julia         #+#    #+#                 */
/*   Updated: 2022/12/04 02:22:21 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			index;

	p = s;
	index = 0;
	while (index < n)
	{
		p[index] = '\0';
		index++;
	}
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*m;

	m = malloc(nelem * elsize);
	if (m == NULL)
		return (NULL);
	ft_bzero(m, nelem * elsize);
	return (m);
}

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}