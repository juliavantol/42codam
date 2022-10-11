/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 15:55:04 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/11 17:10:53 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"
#include <string.h>

int	main(void)
{

	char s[50] = "GeeksForGeeks is for programming geeks.";
	ft_bzero(s + 10, 3);
	printf("My function: %s\n", s);

	char ss[50] = "GeeksForGeeks is for programming geeks.";
	bzero(ss + 10, 3);
	printf("Actual function: %s\n", ss);
	// unsigned char c = '$';
	// printf("Real function: %c\n", tolower(c));
	// printf("My function: %c\n", ft_tolower(c))
	


}