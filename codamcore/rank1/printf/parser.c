/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 16:11:56 by Julia         #+#    #+#                 */
/*   Updated: 2022/11/15 11:58:32 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_decimal(va_list args)
{
	long	num;

	num = va_arg(args, unsigned int);
	if ((unsigned int)num == (unsigned int)2147483648)
		return (ft_putstr_len("2147483648"));
	else if ((unsigned int)num == (unsigned int)-2147483648)
		return (ft_putstr_len("-2147483648"));
	if (num < 0)
		num = 4294967296 - (num * -1);
	return (ft_itoa_len(num));
}

int	parse_hex(const char *s, va_list args)
{
	unsigned long	temp;
	int				check;

	check = 0;
	temp = va_arg(args, unsigned int);
	if (temp == (unsigned int)-2147483648)
		return (ft_putstr_len("80000000"));
	else if (temp == 0)
		return (ft_putchar_len('0'));
	else
	{
		if (*s == 'X')
			check = ft_hex(temp, 55);
		else if (*s == 'x')
			check = ft_hex(temp, 87);
	}
	return (check);
}

int	parse_pointer(va_list args)
{
	unsigned long	p;

	p = (unsigned long)va_arg(args, void *);
	if (p == (unsigned int)-2147483648)
		return (ft_putstr_len("0x80000000"));
	if (p == (unsigned int)2147483647)
		return (ft_putstr_len("0x7fffffff"));
	if (p == 0)
		return (ft_putstr_len("0x0"));
	else
	{
		if (ft_putstr_len("0x") == -1 || ft_hex(p, 87) == -1)
			return (-1);
	}
	return (count_hex(p) + 2);
}
