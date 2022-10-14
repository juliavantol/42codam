/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 18:50:58 by Julia         #+#    #+#                 */
/*   Updated: 2022/10/14 13:25:40 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*csrc;
	char	*cdest;
	char	*temp[100];
	size_t	index;

	csrc = (char *) src;
	cdest = (char *) dest;
	index = 0;
	while (index < n)
	{
		temp[index] = &csrc[index];
		index++;
	}
	index = 0;
	while (index < n)
	{
		cdest[index] = *temp[index];
		index++;
	}
	return (cdest);
}
