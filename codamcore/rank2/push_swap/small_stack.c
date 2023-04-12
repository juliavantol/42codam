/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 15:06:45 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/12 17:41:21 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_swap swap)
{
	t_node	*temp;
	int		value;
	int		prev_value;

	temp = *(swap.stack_a);
	prev_value = temp -> value;
	value = prev_value;
	while (temp != NULL)
	{
		value = temp -> value;
		if (prev_value > value)
			return (0);
		prev_value = temp -> value;
		temp = temp -> next;
	}
	return (1);
}

void	small_sort(t_swap swap, int first, int second, int third)
{
	first = (*(swap.stack_a))-> value;
	second = (*(swap.stack_a))-> next -> value;
	third = (*(swap.stack_a))-> next -> next -> value;
	if (first == 0)
	{
		ft_reverse_rotate(swap.stack_a);
		ft_swap(swap.stack_a);
	}
	else if (first == 1)
	{
		if (second == 0)
			ft_swap(swap.stack_a);
		else
			ft_reverse_rotate(swap.stack_a);
	}
	else if (first == 2)
	{
		if (second == 1)
		{
			ft_rotate(swap.stack_a);
			ft_swap(swap.stack_a);
		}
		else
			ft_rotate(swap.stack_a);
	}
}

void	small_sort_5(t_swap swap)
{
	t_node	*temp;
	int		index;
	int		val;
	int		min;
	int		steps;
	int		i;

	index = 0;
	min = 0;
	val = 0;
	temp = *(swap.stack_a);
	// printf("a: \n");
	// print_stack((*(swap.stack_a)));
	// printf("b: \n");
	// print_stack((*(swap.stack_b)));
	// printf("\n\n");
	while (temp)
	{
		val = temp -> value;
		i = 0;
		if (min == val)
		{
			steps = index - val;
			while (i < steps)
			{
				ft_rotate(swap.stack_a);
				i++;
			}
			ft_push(swap.stack_a, swap.stack_b, 'b');
		}
		temp = temp -> next;
		index++;
	}
	// printf("after:\n\n");
	// printf("a: \n");
	// print_stack((*(swap.stack_a)));
	// printf("b: \n");
	print_stack((*(swap.stack_b)));
	// printf("\n\n");
}
