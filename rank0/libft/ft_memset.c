/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:39:25 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/05 14:48:43 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*memset(void *s, int c, size_t n)
{
	// *s = memory area/string
	// constant byte
	// n = first n bytes of memory
	// fill first n bytes of memory pointed to by *s with constant byte c
	int	index;
	void	*new;

	new = s;

	index = 0;
	while (index < n)
	{
		// s[index] = c;
		index++;
	}
	return (0);
}