/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 12:48:08 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/17 16:58:59 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp -> value);
		temp = temp -> next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**input;
	t_swap	swap;
	int		arg_len;

	arg_len = 0;
	if (argc < 2)
		exit(1);
	parse_input(argv, 0, 0);
	exit(1);
	input = check_input(argc, argv, &arg_len);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_simplify_input(input, arg_len, stack_a);
	swap.stack_a = stack_a;
	swap.stack_b = stack_b;
	if (is_sorted(swap) == 1)
		exit(1);
	swap.stack_size = ft_stacksize(*stack_a);
	swap.max_len = max_digit(swap.stack_size);
	if (swap.stack_size == 3)
		small_sort(swap.stack_a, 0, 0, 0);
	else if (swap.stack_size == 5)
		small_sort_5(swap);
	else
		ft_sort(swap, 0, 0);
}
