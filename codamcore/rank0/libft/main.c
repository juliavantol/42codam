/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 13:35:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/15 16:00:33 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	// char dst[100] = "1234";	
	// char src[100] = "56789012345";
	// ft_strlcat(dst, src, 16);
	// printf("%s\n", dst);
	size_t	result;
	char dest[10] = "a";
    
	result = ft_strlcat(dest, "lorem ipsum dolor sit amet", 1);
	printf("%s\n", dest);
	printf("%zu\n", result);
}

