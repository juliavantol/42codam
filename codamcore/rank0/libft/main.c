/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 13:35:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/26 11:24:02 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	test_atoi(void)
// {
// 	printf("Answer: %d\n", atoi("\t\n\r\v\f  -469 \n"));
// 	printf("Mine: %d\n", ft_atoi("\t\n\r\v\f  -469 \n"));
// 	printf("Answer: %d\n", atoi("+123"));
// 	printf("Mine: %d\n", ft_atoi("+123"));
// }

void	test_split(void)
{
	char	**split;

	split = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	int		index;
	index = 0;
	while (split[index] != 0)
	{
		printf("%s\n", split[index]);
		index++;
	}
}

// void test_itoa(void)
// {
// 	printf("%s\n", ft_itoa(123));
// }

int	main(void)
{
	test_split();
}
