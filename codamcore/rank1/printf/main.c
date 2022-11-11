/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 17:46:04 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/12 00:57:42 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	// long	a;
	// void	*p;

	// a = 9223372036854775807;
	// p = &a;
	unsigned long a = 18446744073709551615;

	printf("\n%d\n", printf("0x%lu-", a));
	printf("\n%d\n", ft_printf("0x%p-", a));
	return (0);
}