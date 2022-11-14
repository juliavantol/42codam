/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ints.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 16:11:56 by Julia         #+#    #+#                 */
/*   Updated: 2022/11/14 11:55:42 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_unsigned_int(va_list args)
{
	int		temp;
	long	new;
	int		count;

	temp = va_arg(args, int);
	new = temp;
	if ((unsigned int)temp == (unsigned int)2147483648)
		return (ft_putstr("2147483648"));
	else if ((unsigned int)temp == (unsigned int)-2147483648)
		return (ft_putstr("-2147483648"));
	if (temp < 0)
	{
		new = 4294967296 - (temp * -1);
		return (ft_itoa_len(new));
	}
	else
		return (ft_itoa_len(temp));
	return (0);
}

int	convert_int(va_list args)
{
	int	temp;
	int	count;

	temp = va_arg(args, int);
	if (temp == 2147483647)
		return (ft_putstr("2147483647"));
	if (temp == -2147483648)
		return (ft_putstr("-2147483648"));
	return (ft_itoa_len(temp));
}
