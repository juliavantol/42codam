/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/06 18:42:51 by Julia         #+#    #+#                 */
/*   Updated: 2022/11/08 17:51:54 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Convert the number with base value 10 to base value 16 */
/* keep diving by 16 and for each turn store the remainder */

void	to_hex(unsigned int num, int format)
{
	int		remainder;

	if (num == 0)
		return ;
	if (num != 0)
		to_hex(num / 16, format);
	remainder = num % 16;
	if (remainder < 10)
		ft_putchar_fd((remainder + 48), 1);
	else
		ft_putchar_fd((remainder + format), 1);
}

int	count_hex(unsigned int n)
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
