/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 13:36:42 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/13 14:02:42 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*m;

	m = malloc(nelem * elsize);
	if (m == 0)
		return (m);
	ft_bzero(m, nelem * elsize);
	return (m);
}
