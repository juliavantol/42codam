/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 13:35:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/16 19:18:41 by Julia         ########   odam.nl         */
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
	char	dest[15] = "r";
	char	*src = "lorem ipsum dolor sit amet";

	memset(dest, 'r', 15);
	result = ft_strlcat(dest, src, 5);
	printf("%s\n", dest);
	printf("%zu\n", result);
}
