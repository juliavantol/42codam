/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_len.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/13 23:30:12 by Julia         #+#    #+#                 */
/*   Updated: 2022/11/13 23:32:09 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	reverse_num(long n)
{
	long	new_num;

	new_num = 0;
	while (n != 0)
	{
		new_num = (new_num * 10) + n % 10;
		n = n / 10;
	}
	return (new_num);
}

int	count_digits(long n)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

int	print_number(long n)
{
	long	num;
	int		index;

	num = reverse_num(n);
	index = 0;
	while (num > 0)
	{
		if (ft_putchar(num % 10 + '0') == -1)
			return (-1);
		num = num / 10;
		index++;
	}
	while (index < count_digits(n))
	{
		if (ft_putchar('0') == -1)
			return (-1);
		index++;
	}
	return (index);
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
