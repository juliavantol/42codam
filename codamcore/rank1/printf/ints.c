/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ints.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 16:11:56 by Julia         #+#    #+#                 */
/*   Updated: 2022/11/08 17:27:12 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_int(va_list args)
{
	int	temp;
	int	count;

	temp = va_arg(args, int);
	count = new_itoa(temp);
	if (count != -1)
		count = count_digits(temp);
	return (count);
}

static int	min_int(int n)
{
	int	count;

	count = 0;
	if (n == 2147483647)
		count = ft_putstr("2147483647");
	if (n == -2147483648)
		count = ft_putstr("-2147483648");
	return (count);
}

static int	recursive_loop(int n)
{
	int	count;
	int	num;
	int	index;

	num = 0;
	count = 0;
	while (n != 0)
	{
		num = (num * 10) + n % 10;
		n = n / 10;
		count++;
	}
	index = 0;
	while (num > 0)
	{
		if (ft_putchar(num % 10 + '0') == -1)
			return (-1);
		num = num / 10;
		index++;
	}
	if (index < count)
	{
		while (index < count)
		{
			if (ft_putchar('0') == -1)
				return (-1);
			index++;
		}
	}
	return (count);
}

int	new_itoa(int n)
{
	int	count;
	int	check;

	count = 0;
	if (n == 0)
		return (ft_putchar('0'));
	count = min_int(n);
	if (count == -1 || count > 0)
		return (count);
	if (n < 0)
	{
		n *= -1;
		count++;
		check = ft_putchar('-');
		if (check == -1)
			return (-1);
	}
	return (recursive_loop(n));
}

int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}
