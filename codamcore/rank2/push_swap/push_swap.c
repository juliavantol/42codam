/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 12:48:08 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/28 14:34:43 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	if (stack != NULL)
	{
		while (temp -> next != NULL)
		{
			printf("%d\n", temp -> value);
			temp = temp -> next;
		}
	}
}

// atexit(leaks);
int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	*new;

	if (argc < 2)
		exit(1);
	check_input(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	new = ft_lstnew((void *)1);
	ft_lstadd_back(stack_a, new);
}
