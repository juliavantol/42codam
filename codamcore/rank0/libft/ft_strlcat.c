/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 09:26:15 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/16 19:18:22 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char * restrict dst, const char * restrict src, size_t size )
{
	int		dst_len;
	int		t_len;
	int		index;
	int		total_to_append;
	int		check;
	int 	found;

	check = size - 1;
	dst_len = ft_strlen(dst);
	index = 0;
	found = 0;
	while (index <= check)
	{
		if (dst[index] == '\0')
			found = 1;
		index++;
	}

	if (size > 0 && found == 1)
	{
		t_len = ft_strlen(src) + dst_len;
		total_to_append = size - dst_len;
		index = 0;
		if (total_to_append > 0)
		{
			while (index < (total_to_append - 1))
			{
				dst[dst_len] = src[index];
				dst_len++;
				index++;
			}
		}
		dst[dst_len] = '\0';
	}
	else
		t_len = ft_strlen(src) + size;
	return (t_len);
}
