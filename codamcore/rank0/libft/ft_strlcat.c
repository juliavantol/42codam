/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 09:26:15 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/16 20:22:53 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* lala */

size_t	ft_strlcat(char *dst, const char *src, size_t size )
{
	int	dst_len;
	int	t_len;
	int	index;
	int	total_to_append;
	int	null_found;

	null_found = 0;
	index = 0;
	while (index <= ((int)size - 1))
	{
		if (dst[index++] == '\0')
			null_found = 1;
	}
	if (size > 0 && null_found == 1)
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
