/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 09:26:15 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/19 15:52:44 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function concatenates dst and src into dst */
/* It returns the length of the string it tried to create */
/* Dst will be not me modified if dst is already fully occupied */
/* meaning that that there's a null character in the first size-1 bytes */

size_t	ft_strlcat(char *dst, const char *src, size_t size )
{
	size_t	dst_len;
	size_t	t_len;
	size_t	index;
	size_t	total_to_append;

	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	if (dst[ft_strlen(dst)] == '\0' && ft_strlen(dst) <= (size - 1) && size > 0)
	{
		dst_len = ft_strlen(dst);
		t_len = ft_strlen(src) + dst_len;
		total_to_append = size - dst_len;
		index = 0;
		if ((size - dst_len) > 0)
		{
			while (index < (total_to_append - 1))
				dst[dst_len++] = src[index++];
		}
		dst[dst_len] = '\0';
		return (t_len);
	}
	else
		return (ft_strlen(src) + size);
}
