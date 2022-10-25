/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 18:50:58 by Julia         #+#    #+#                 */
/*   Updated: 2022/10/25 15:08:13 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

/* Copies n bytes from memory area src to memory area dest.*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;
	size_t			index;

	if (!dest && !src)
		return (NULL);
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
		return ((void *)cdest);
	}
	index = n - 1;
	while ((int)index >= 0)
	{
		cdest[index] = csrc[index];
		index--;
	}
	return ((void *)cdest);
}
