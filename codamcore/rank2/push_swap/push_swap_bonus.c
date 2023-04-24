/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 14:32:43 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/24 14:42:48 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Initialise the stacks */
t_ps	init_stacks(void)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	t_ps	ps;

	stack_a = (t_stack **)malloc(sizeof(t_stack));
	if (!stack_a)
		exit(1);
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	if (!stack_b)
		exit(1);
	*stack_a = NULL;
	*stack_b = NULL;
	ps.stack_a = stack_a;
	ps.stack_b = stack_b;
	return (ps);
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	int		size;

	if (argc < 2)
		exit(1);
	ps = init_stacks();
	handle_input(ps.stack_a, argv);
	size = stack_size(*(ps.stack_a));
	ps.arg_len = size;
	if (size == 3)
		sort_3(ps.stack_a);
	else if (size == 5)
		sort_5(ps, 0, 0);
	else
		sort_big(ps, 0, 0, max_digit(size));
	if (is_sorted(ps.stack_a) == 1 && stack_size(*(ps.stack_b)) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
