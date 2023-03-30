/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 12:48:08 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/30 15:59:33 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *head)
{
	t_node	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%d, %p, next: %p\n", temp -> value, temp, temp -> next);
		temp = temp -> next;
	}
}

// atexit(leaks);
int	main(int argc, char **argv)
{
	t_node	**stack_a;
	char	**input;

	if (argc < 2)
		exit(1);
	input = check_input(argc, argv);
	stack_a = (t_node **)malloc(sizeof(t_node));
	*stack_a = NULL;
	fill_stack(input, stack_a);
	print_stack(*stack_a);
}
