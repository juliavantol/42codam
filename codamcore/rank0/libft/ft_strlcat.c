/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 09:26:15 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/15 17:08:24 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size )
{
	size_t	t_len;
	size_t	index;
	size_t	dst_len;
	size_t	total_to_append;

	if (!dst && !src && !size)
		return (0);

	// append at most dstsize - strlen(dst) - 1 characters
	dst_len = ft_strlen(dst);
	if (size > 0)
	{
		total_to_append = size - dst_len;
		index = 0;
		if (total_to_append > 0)
		{
			t_len = (ft_strlen(src) + ft_strlen(dst));
			while (index < (total_to_append - 1))
			{
				dst[dst_len] = src[index];
				dst_len++;
				index++;
			}
		}
		else
			t_len = ft_strlen(src) + ft_strlen(dst);
		dst[dst_len] = '\0';
	}
	else
	{
		t_len = (ft_strlen(src) + ft_strlen(dst)) - 1;
		dst[dst_len] = '\0';
	}
	return (t_len);	
}
