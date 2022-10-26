/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 13:35:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/26 13:35:51 by juvan-to      ########   odam.nl         */
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

// void	test_split(void)
// {
// 	char	**split;
// 	int		index;

// 	split = ft_split("lorem ipsum dolor sit amet, consectetur", ' ');
// 	index = 0;
// 	while (split[index] != 0)
// 	{
// 		printf("%s\n", split[index]);
// 		index++;
// 	}
// }

// void	test_itoa(void)
// {
// 	printf("%s\n", ft_itoa(123));
// }

// void	test_substr(void)
// {
// 	// printf("%s\n", ft_substr("hola", 0, 18446744073709551615));
// 	printf("%s\n", ft_substr("Dit is een zin", 0, 3));
// 	printf("%s\n", ft_substr("Dit is een zin", 5, 3));
// }

// void	test_lstnew(void)
// {
// 	ft_lstnew("hallo?");
// }

void	test_lstadd_front(void)
{
	t_list	*begin;
	t_list	*elem;
	t_list	*elem2;
	char	*str = strdup("lorem");
	char	*str2 = strdup("ipsum");

	begin = NULL;
	elem = malloc(sizeof(t_list));
	elem2 = malloc(sizeof(t_list));
	elem -> content = str;
	elem2 -> content = str2;
	ft_lstadd_front(&begin, elem);
	ft_lstadd_front(&begin, elem2);
}

int	main(void)
{
	test_lstadd_front();
}
