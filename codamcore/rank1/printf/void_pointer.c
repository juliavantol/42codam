/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   void_pointer.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 12:30:20 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/08 17:37:31 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointer(va_list args, int count)
{
	unsigned long	p;

	p = (unsigned long)va_arg(args, void *);
	if (p == -2147483648 || p == 2147483648)
	{
		p = (unsigned int)p;
		ft_putstr("0x");
		count = 11;
		pointer_to_hex(p, 87);
	}
	else if (p == 0)
		count = ft_putstr("0x0");
	else
	{
		count = ft_putstr("0x");
		count = count_hex_long(p);
		pointer_to_hex(p, 87);
	}
	return (count);
}

void	pointer_to_hex(unsigned long num, int format)
{
	int	remainder;

	if (num == 0)
		return ;
	if (num != 0)
		pointer_to_hex(num / 16, format);
	remainder = num % 16;
	if (remainder < 10)
		ft_putchar_fd((remainder + 48), 1);
	else
		ft_putchar_fd((remainder + format), 1);
}

int	count_hex_long(unsigned long n)
{
	int		index;

	index = 0;
	if (n == (unsigned int)-2147483648)
		return (0);
	while (n != 0)
	{		
		n = n / 16;
		index++;
	}
	return (index);
}