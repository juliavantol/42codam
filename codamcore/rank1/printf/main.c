/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 17:46:04 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/04 13:53:38 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	*b;
	int		res1;
	int		res2;

	b = "cletter";
	ft_printf("Hello this is a string number c: %c and s: %s\n", 'a', b);
	res1 = printf(" %c %c %c ", '0', 0, '1');
	res2 = ft_printf(" %c %c %c ", '0', 0, '1');
	printf("\nanswer: %d mine: %d\n", res1, res2);
	return (0);
}
