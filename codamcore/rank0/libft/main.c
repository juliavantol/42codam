/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 13:35:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/27 13:02:36 by juvan-to      ########   odam.nl         */
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

// void	test_lstadd_front(void)
// {
// 	//
// }

// void	test_lsize(void)
// {
// 	t_list	*l;

// 	l = ft_lstnew(ft_strdup("1"));
// 	l->next = ft_lstnew(ft_strdup("2"));
// 	l->next->next = ft_lstnew(ft_strdup("3"));
// 	printf("%d\n", ft_lstsize(l));

// }

// void	test_llast(void)
// {
// 	t_list	*l;
// 	t_list *expected;
// 	t_list *actual;

// 	l = ft_lstnew(ft_strdup("1"));
// 	l->next = ft_lstnew(ft_strdup("2"));
// 	l->next->next = ft_lstnew(ft_strdup("3"));
// 	expected = l->next->next;
//     actual = ft_lstlast(l);
// 	if (actual == expected)
// 		printf("Correct!\n");
// 	else
// 		printf("Incorrect\n");
// }

void	test_lstback(void)
{
	t_list	*l;
	t_list	*new;
	// t_list	*expected;
	// t_list	*actual;

	l = ft_lstnew(ft_strdup("1"));
	l->next = ft_lstnew(ft_strdup("2"));
	l->next->next = ft_lstnew(ft_strdup("3"));
	new = ft_lstnew(ft_strdup("4"));
	new -> next = ft_lstnew(ft_strdup("5"));
	// expected = l->next->next;
    ft_lstadd_back(&l, new);
// 	if (actual == expected)
// 		printf("Correct!\n");
// 	else
// 		printf("Incorrect\n");
}

int	main(void)
{
	test_lstback();
}
