/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 09:26:15 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/15 18:38:55 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size )
{
	int		dst_len;
	int		t_len;
	int		index;
	int		total_to_append;

	dst_len = ft_strlen(dst);
	if (size > 0)
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
	}
	else
		t_len = ft_strlen(src);

	dst[dst_len] = '\0';
	return (t_len);
}
