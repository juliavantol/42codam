/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 18:50:58 by Julia         #+#    #+#                 */
/*   Updated: 2022/10/14 16:33:49 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;
	size_t			index;

	csrc = (unsigned char *) src;
	cdest = (unsigned char *) dest;
	index = 0;
	if (cdest < csrc)
	{
		while (index < n)
		{
			cdest[index] = csrc[index];
			index++;
		}
	}
	else
	{
		index = n - 1;
		while ((int)index >= 0)
		{
			cdest[index] = csrc[index];
			index--;
		}
	}
	return ((void *)cdest);
}
