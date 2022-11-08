/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unsigned_ints.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 11:14:55 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/08 17:45:05 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_unsigned_int(const char *s, va_list args, int count)
{
	unsigned int	temp;

	temp = va_arg(args, unsigned int);
	if (temp == (unsigned int)-2147483648)
		count = ft_putstr("80000000");
	else if (temp == 0)
		count = ft_putchar('0');
	else
	{
		count = count_hex(temp);
		if (*s == 'X')
			to_hex(temp, 55);
		else if (*s == 'x')
			to_hex(temp, 87);
	}
	return (count);
}
