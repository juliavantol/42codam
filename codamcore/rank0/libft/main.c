/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 13:35:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/15 18:37:46 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	// char dst[100] = "1234";	
	// char src[100] = "567890";
	// strlcat(dst, src, 8);
	// printf("%s\n", dst);
	size_t	result;
	char	dest[10] = "a";

	result = strlcat(dest, "123456789", 0);
	printf("%s\n", dest);
	printf("%zu\n", result);
}
