/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_len.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 12:42:31 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/14 12:44:40 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_len(char *s)
{
	if (!s)
	{
		return (write(1, "(null)", 6));
	}
	else
		return (write(1, s, ft_strlen(s)));
	return (ft_strlen(s));
}
