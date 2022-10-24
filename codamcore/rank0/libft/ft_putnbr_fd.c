/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 15:09:13 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/24 16:44:36 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Outputs the integer ’n’ to the given file descriptor. */

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
		return (ft_putnbr_fd(n, fd));
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		return (ft_putnbr_fd(n % 10, fd));
	}
	else
		ft_putchar_fd(n + 48, fd);
}
