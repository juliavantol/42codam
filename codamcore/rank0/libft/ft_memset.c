/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:39:25 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/14 11:28:04 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*new;
	size_t			index;

	index = 0;
	new = s;
	while (index < n)
	{
		new[index] = c;
		index++;
	}
	return (new);
}
