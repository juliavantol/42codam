/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 13:35:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/25 12:28:55 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	test_atoi(void)
{
	printf("Answer: %d\n", atoi("\t\n\r\v\f  -469 \n"));
	printf("Mine: %d\n", ft_atoi("\t\n\r\v\f  -469 \n"));
	printf("Answer: %d\n", atoi("+123"));
	printf("Mine: %d\n", ft_atoi("+123"));
}


int	main(void)
{
	test_atoi();
}

// char	*ft_itoa(int n)
// {
// 	char	*str;
// 	int		reverse;
// 	int		multi;

// 	str = "a";
// 	if (!str)
// 		return (NULL);
// 	reverse = 0;
// 	multi = 1;
// 	while (n >= 10)
// 	{
// 		reverse += ((n % 10) * multi);
// 		multi *= 10;
// 		n = n / 10;
// 	}
// 	reverse += ((n % 10) * multi);
// 	printf("%d\n", reverse);
// 	return (str);
// }
