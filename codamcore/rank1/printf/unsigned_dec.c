/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unsigned_dec.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/13 02:37:53 by Julia         #+#    #+#                 */
/*   Updated: 2022/11/13 19:13:44 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	un_min_int(long n)
{
	int	count;

	count = 0;
	if ((unsigned int)n == (unsigned int)2147483648)
		count = ft_putstr("2147483648");
	else if ((unsigned int)n == (unsigned int)-2147483648)
		count = ft_putstr("-2147483648");
	return (count);
}

int	new_itoa_un(long n)
{
	int	count;
	int	check;

	count = 0;
	if (n == 0)
		return (ft_putchar('0'));
	count = un_min_int(n);
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
	return (print_number(n));
}
