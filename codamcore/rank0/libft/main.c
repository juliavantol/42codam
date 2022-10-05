/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 15:55:04 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/05 14:50:47 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"
#include <string.h>

int	main(void)
{

	const char *s = "hello there";

	// unsigned char c = '$';
	// printf("Real function: %c\n", tolower(c));
	// printf("My function: %c\n", ft_tolower(c));

	printf("My function: %c\n", ft_memset(s, 'a', 3));


}