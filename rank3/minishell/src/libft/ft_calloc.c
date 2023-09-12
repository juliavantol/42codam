/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 13:36:42 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/12 13:45:29 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Allocates specified amount of memory and initializes it to zero */

void	ft_bzero(void *s, int n)
{
	unsigned char	*p;
	int			index;

	p = s;
	index = 0;
	while (index < n)
	{
		p[index] = '\0';
		index++;
	}
}

void	*ft_calloc(int nelem, int elsize)
{
	void	*m;

	m = malloc(nelem * elsize);
	if (m == NULL)
		return (NULL);
	ft_bzero(m, nelem * elsize);
	return (m);
}