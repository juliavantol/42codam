/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 12:48:08 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/30 17:49:59 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *head)
{
	t_node	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp -> value);
		temp = temp -> next;
	}
}

// atexit(leaks);
int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;
	char	**input;

	if (argc < 2)
		exit(1);
	input = check_input(argc, argv);
	stack_a = (t_node **)malloc(sizeof(t_node));
	stack_b = (t_node **)malloc(sizeof(t_node));
	*stack_a = NULL;
	*stack_b = NULL;
	fill_stack(input, stack_a);

	ft_rotate(stack_a);
	printf("STACK A:\n");
	print_stack(*stack_a);
	printf("\n\n\n");
	printf("STACK B:\n");
	print_stack(*stack_b);

	// ft_push(stack_a, stack_b);
	// ft_push(stack_a, stack_b);
	// ft_push(stack_b, stack_a);
	// ft_push(stack_b, stack_a);
}
