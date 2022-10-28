/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 13:35:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/28 13:45:56 by juvan-to      ########   odam.nl         */
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

void	ft_print_result(t_list *elem)
{
	int		len;

	len = 0;
	while (((char *)elem->content)[len])
		len++;
	write(1, elem->content, len);
	write(1, "\n", 1);
}

// void	test_lstback(void)
// {
// 	t_list	*begin;
// 	t_list	*new;

// 	begin = ft_lstnew(ft_strdup("1"));
// 	begin->next = ft_lstnew(ft_strdup("2"));
// 	begin->next->next = ft_lstnew(ft_strdup("3"));
// 	new = ft_lstnew(ft_strdup("4"));
// 	ft_lstadd_back(&begin, new);
// 	while (begin)
// 	{
// 		ft_print_result(begin);
// 		begin = begin->next;
// 	}
// }

// void	test_lstdelone(void)
// {
// 	t_list	*l;

// 	l = ft_lstnew(ft_strdup("1"));
// 	l->next = ft_lstnew(ft_strdup("2"));
// 	ft_lstdelone(l, &free);
// }

// void	test_lstclear(void)
// {
// 	t_list	*l;

// 	l = ft_lstnew(ft_strdup("1"));
// 	l->next = ft_lstnew(ft_strdup("2"));
// 	l->next->next = ft_lstnew(ft_strdup("3"));
// 	ft_lstclear(&l, &free);
// }

void	ft_modify_list_with_d(void *elem)
{
	int		len;
	char	*content;

	len = 0;
	content = (char *)elem;
	while (content[len])
	{
		content[len++] = 'd';
	}
}

void	*ft_map(void *ct)
{
	int		i;
	void	*c;
	char	*pouet;

	c = ct;
	i = -1;
	pouet = (char *)c;
	while (pouet[++i])
		if (pouet[i] == 'o')
			pouet[i] = 'a';
	return (c);
}
// void	test_lstiter(void)
// {
// 	t_list	*l;

// 	l = ft_lstnew(ft_strdup("1"));
// 	l->next = ft_lstnew(ft_strdup("2"));
// 	l->next->next = ft_lstnew(ft_strdup("3"));
// 	ft_lstiter(l, &ft_modify_list_with_d);
// }

void	test_lstmap(void)
{
	t_list	*l;
	t_list	*list;

	l = ft_lstnew(ft_strdup("lorem"));
	l->next = ft_lstnew(ft_strdup("ipsum"));
	l->next->next = ft_lstnew(ft_strdup("dolor"));
	list = ft_lstmap(l, &ft_map, &free);
	ft_print_result(list);
}

int	main(void)
{
	test_lstmap();
}
