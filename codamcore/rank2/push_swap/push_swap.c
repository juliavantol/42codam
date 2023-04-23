/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 12:48:08 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/23 23:24:48 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%d -> %d\n", temp -> value, temp -> index);
		temp = temp -> next;
	}
}

t_swap	init_stacks(void)
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
	swap.stack_a = stack_a;
	swap.stack_b = stack_b;
	return (swap);
}

int	main(int argc, char **argv)
{
	t_swap	swap;
	int		arg_len;

	arg_len = 0;
	if (argc < 2)
		exit(1);
	swap = init_stacks();
	handle_input(swap, argv, &arg_len);
	if (arg_len == 3)
		sort_3(swap.stack_a);
	else if (arg_len == 5)
		sort_5(swap, arg_len);
	else
		sort_big(swap, 0, 0, arg_len);
}
