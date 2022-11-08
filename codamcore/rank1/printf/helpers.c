/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/05 17:04:02 by Julia         #+#    #+#                 */
/*   Updated: 2022/11/08 16:26:09 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	if (!s)
	{
		return (write(1, "(null)", 6));
	}
	else
		return (write(1, s, ft_strlen(s)));
	return (ft_strlen(s));
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
