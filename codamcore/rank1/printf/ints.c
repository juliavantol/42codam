/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ints.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 16:11:56 by Julia         #+#    #+#                 */
/*   Updated: 2022/11/13 19:20:54 by Julia         ########   odam.nl         */
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
	new = 0;
	if (temp < 0)
	{
		new = 4294967296 - (temp * -1);
		count = new_itoa_un(new);
		if (count != -1)
			count = count_digits(new);
	}
	else
	{
		count = new_itoa(temp);
		if (count != -1)
			count = count_digits(temp);
	}
	return (count);
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
	count = new_itoa(temp);
	if (count != -1)
		count = count_digits(temp);
	return (count);
}

int	new_itoa(long n)
{
	int	check;

	if (n == 0)
		return (ft_putchar('0'));
	if (n < 0)
	{
		n *= -1;
		check = ft_putchar('-');
		if (check == -1)
			return (-1);
	}
	return (print_number(n));
}
