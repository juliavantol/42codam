/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 15:55:04 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/11 18:22:35 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"
#include <string.h>

int	main(void)
{

	const char src[50] = "Hello this is a sentence";
   	char dest[50];
	memcpy(dest, src, strlen(src)+1);
	printf("memcpy: %s\n", dest);

	const char src2[50] = "Hello this is a sentence";
   	char dest2[50];
	ft_memcpy(dest2, src2, strlen(src2)+1);
	printf("ft_memcpy: %s\n", dest2);
	// unsigned char c = '$';
	// printf("Real function: %c\n", tolower(c));
	// printf("My function: %c\n", ft_tolower(c))
	
}