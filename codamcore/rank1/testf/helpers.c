/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/05 17:04:02 by Julia         #+#    #+#                 */
/*   Updated: 2022/11/08 00:35:51 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		return (write(1, s, ft_strlen(s)));
	return (ft_strlen(s));
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static void	recursive_loop(int n)
{
	if (n > 9)
		recursive_loop(n / 10);
	ft_putchar_fd((n % 10 + '0'), 1);
}

static int	min_int(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count = ft_putstr("-2147483648");
	return (count);
}

int	new_itoa(int n)
{
	int	count;

	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	count = min_int(n);
	if (count != 0)
		return (count);
	if (n < 0)
	{
		n *= -1;
		count++;
		ft_putchar_fd('-', 1);
	}
	recursive_loop(n);
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}
