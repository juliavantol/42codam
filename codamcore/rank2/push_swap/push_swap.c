/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 12:48:08 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/06 18:13:07 by juvan-to      ########   odam.nl         */
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

// with sequence [2 1 3 6 5 8] 2 is the top of the stack
int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;
	char	**input;
	int		max_len;
	int		arg_len;

	arg_len = 0;
	if (argc < 2)
		exit(1);
	input = check_input(argc, argv, &arg_len);
	stack_a = (t_node **)malloc(sizeof(t_node));
	stack_b = (t_node **)malloc(sizeof(t_node));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_simplify(input, arg_len, stack_a);
	// fill_stack(input, stack_a);
	max_len = max_digit(*stack_a);

	
	// ft_swap(stack_a);
	// ft_push(stack_a, stack_b);
	// ft_push(stack_a, stack_b);
	// ft_push(stack_a, stack_b);
	// ft_rotate(stack_a);
	// ft_rotate(stack_b);
	// ft_reverse_rotate_both(stack_a, stack_b);
	// ft_swap(stack_a);
	// ft_push(stack_b, stack_a);
	// ft_push(stack_b, stack_a);
	// ft_push(stack_b, stack_a);

	printf("_____________\n");
	printf("STACK A:\n");
	print_stack(*stack_a);
	printf("\n");
	printf("STACK B:\n");
	print_stack(*stack_b);

	// ft_sort(stack_a, max_len);
	// leaks();

}
