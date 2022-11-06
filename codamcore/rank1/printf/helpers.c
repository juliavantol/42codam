/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/05 17:04:02 by Julia         #+#    #+#                 */
/*   Updated: 2022/11/06 02:43:56 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int fd)
{
	size_t	index;

	index = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		index = 6;
	}
	else
	{
		while (index < ft_strlen(s))
		{
			write(fd, &s[index], 1);
			index++;
		}
	}
	return (index);
}

static void	recursive_loop(int n)
{
	if (n > 9)
		recursive_loop(n / 10);
	ft_putchar_fd((n % 10 + '0'), 1);
}

int	new_itoa(int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
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