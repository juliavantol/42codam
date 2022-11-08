/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/05 17:04:02 by Julia         #+#    #+#                 */
/*   Updated: 2022/11/08 13:59:04 by juvan-to      ########   odam.nl         */
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

static int	min_int(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count = ft_putstr("-2147483648");
	return (count);
}

static int	recursive_loop(int n)
{
	if (n > 9)
		recursive_loop(n / 10);
	if (ft_putchar(n % 10 + '0') == -1)
		return (-1);
	return (0);
}

int	new_itoa(int n)
{
	int	count;
	int	check;

	if (n == 0)
		return (ft_putchar('0'));
	count = min_int(n);
	if (count != 0)
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
