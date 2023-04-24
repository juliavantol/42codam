/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 12:48:08 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/24 14:03:06 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks(void)
{
	system ("leaks push_swap");
}

void	print_stack(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%d -- %d\n", temp -> value, temp -> index);
		temp = temp -> next;
	}
}

void	print_stack_i(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp -> index);
		temp = temp -> next;
	}
}

t_swap	init_stacks(t_temp	*input, int arg_len)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	t_swap	swap;

	stack_a = (t_stack **)malloc(sizeof(t_stack));
	if (!stack_a)
		exit(1);
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	if (!stack_b)
		exit(1);
	*stack_a = NULL;
	*stack_b = NULL;
	fill_stack2(input, stack_a, arg_len);
	swap.stack_a = stack_a;
	swap.stack_b = stack_b;
	return (swap);
}

int	main(int argc, char **argv)
{
	t_temp	*input;
	t_swap	swap;
	int		arg_len;

	arg_len = 0;
	if (argc < 2)
		exit(1);
	input = handle_input(argv, &arg_len);
	swap = init_stacks(input, arg_len);
	if (is_sorted(swap) == 1)
		exit(1);
	if (arg_len == 3)
		rev_sort_3(swap.stack_a);
	else if (arg_len == 5)
		small_sort_5(swap, arg_len);
	else
		ft_sort(swap, 0, 0, arg_len);
	leaks();
}
