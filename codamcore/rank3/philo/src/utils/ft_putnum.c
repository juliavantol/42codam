/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnum.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 12:40:15 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/06/12 12:49:32 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putnum(int n)
{
	if (n == -2147483648)
		put_str("-2147483648", 1);
	if (n < 0)
	{
		n *= -1;
		put_char('-');
		return (ft_putnum(n));
	}
	else if (n >= 10)
	{
		ft_putnum(n / 10);
		return (ft_putnum(n % 10));
	}
	else
		put_char(n + 48);
}
