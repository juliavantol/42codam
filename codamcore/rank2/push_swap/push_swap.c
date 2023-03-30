/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 12:48:08 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/30 12:46:20 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	if (stack != NULL)
	{
		while (temp != NULL)
		{
			printf("%d, next: %p\n", temp -> value, temp -> next);
			temp = temp -> next;
		}
	}
	else
		printf("Stack is null\n");
}

// atexit(leaks);
int	main(int argc, char **argv)
{
	t_node	*stack_a;

	if (argc < 2)
		exit(1);
	check_input(argc, argv);
	stack_a = NULL;
	stack_a = (t_node *) malloc(sizeof(t_node));
	stack_a->value = 1;
	stack_a->next = NULL;
	ft_addnode(&stack_a, ft_newnode(2));
	ft_addnode(&stack_a, ft_newnode(3));
	ft_addnode(&stack_a, ft_newnode(4));
	print_stack(stack_a);
}
