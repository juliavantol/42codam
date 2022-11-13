/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ints.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 16:11:56 by Julia         #+#    #+#                 */
/*   Updated: 2022/11/13 23:25:01 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(long n);

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
		return (new_itoa(new));
	}
	else
		return (new_itoa(temp));
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
	return (new_itoa(temp));
}

int	new_itoa(long n)
{
	int	str_len;
	int	negative;

	negative = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n < 0)
	{
		n *= -1;
		negative++;
		if (ft_putchar('-') == -1)
			return (-1);
	}
	str_len = print_number(n);
	if (str_len == -1)
		return (-1);
	return (str_len + negative);
}
