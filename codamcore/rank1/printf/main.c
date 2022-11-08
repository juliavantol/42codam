/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 17:46:04 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/08 17:44:32 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	printf("\n%d\n", printf("dgs %x xx", 10));
	printf("\n%d\n", ft_printf("dgs %x xx", 10));
	return (0);
}