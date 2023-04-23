/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 15:06:45 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/22 11:44:46 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_value(t_stack	**stack)
{
	t_stack	*temp;
	int		value;
	int		index;
	int		biggest_index;

	temp = *stack;
	value = temp -> index;;
	index = 0;
	while (temp != NULL)
	{
		if (temp -> index > value)
		{
			value = temp -> index;
			biggest_index = index;
		}
		index++;
		temp = temp -> next;
	}
	return (value);
}

void	rev_sort_3(t_stack	**stack)
{
	int		value;
	t_stack	*head;

	value = biggest_value(stack);
	head = (*stack);
	if (head -> index == value)
		ft_rotate(stack);
	else if (head -> next -> index == value)
		ft_reverse_rotate(stack);
	head = (*stack);
	if (head -> index > head -> next -> index)
		ft_swap(stack, 'a');
}

void	sort_3(t_stack	**stack)
{
	int		highest;
	t_stack	*head;

	highest = biggest_value(stack);
	head = (*stack);
	if (head -> index == highest)
		ft_rotate(stack);
	else if (head -> next -> index == highest)
		ft_reverse_rotate(stack);
	head = (*stack);
	if (head -> index > head -> next -> index)
		ft_swap(stack, 'a');
}

int	is_sorted(t_swap swap)
{
	t_stack	*temp;
	int		value;
	int		prev_value;

	temp = *(swap.stack_a);
	prev_value = temp -> index;
	value = prev_value;
	while (temp != NULL)
	{
		value = temp -> index;
		if (prev_value > value)
			return (0);
		prev_value = temp -> index;
		temp = temp -> next;
	}
	return (1);
}

void	small_sort_5(t_swap swap, int arg_len)
{
	t_stack	*temp;
	int		index;
	int		val;

	index = 0;
	val = 0;
	temp = *(swap.stack_a);
	while (index < arg_len)
	{
		val = temp -> index;
		if (val < 2)
		{
			ft_push(swap.stack_a, swap.stack_b, 'b');
			temp = temp -> next;
		}
		else
		{
			ft_rotate(swap.stack_a);
			temp = *(swap.stack_a);
		}
		index++;
	}
	if (is_sorted(swap) == 0)
		sort_3(swap.stack_a);
	temp = *(swap.stack_b);
	if (temp -> index < temp -> next -> index)
		ft_swap(swap.stack_b, 'b');
	empty_b(swap);
}
