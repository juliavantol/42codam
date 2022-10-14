/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 09:26:15 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/14 17:50:41 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size )
{
	size_t	t_len;
	size_t	index;
	size_t	dst_len;

	t_len = ((ft_strlen(src) + ft_strlen(dst)) - 1);
	dst_len = ft_strlen(dst);
	index = 0;
	if (size != 0)
	{
		while (index <= (size - dst_len))
		{
			dst[dst_len] = src[index];
			dst_len++;
			index++;
		}
	}
	return (t_len);	
}
