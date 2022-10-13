/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 17:18:52 by Julia         #+#    #+#                 */
/*   Updated: 2022/10/13 08:23:18 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *new = (char *) dest;
	char *old = (char *) src;
	size_t	index;

	index = 0;
	while (index < n)
	{
        new[index] = old[index];
        index++;
	}
    new[index] = '\0';
	dest = new;
	return (dest);
}