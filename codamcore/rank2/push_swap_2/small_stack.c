/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 15:06:45 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/17 15:47:32 by juvan-to      ########   odam.nl         */
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
	value = temp -> value;;
	index = 0;
	while (temp != NULL)
	{
		if (temp -> value > value)
		{
			value = temp -> value;
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
	if (head -> value == value)
		ft_rotate(stack);
	else if (head -> next -> value == value)
		ft_reverse_rotate(stack);
	head = (*stack);
	if (head -> value > head -> next -> value)
		ft_swap(stack);
}

int	is_sorted(t_swap swap)
{
	t_stack	*temp;
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

void	small_sort(t_stack	**stack, int first, int second, int third)
{
	first = (*(stack))-> value;
	second = (*(stack))-> next -> value;
	third = (*(stack))-> next -> next -> value;
	if (first == 0)
	{
		ft_reverse_rotate(stack);
		ft_swap(stack);
	}
	else if (first == 1)
	{
		if (second == 0)
			ft_swap(stack);
		else
			ft_reverse_rotate(stack);
	}
	else if (first == 2)
	{
		if (second == 1)
		{
			ft_rotate(stack);
			ft_swap(stack);
		}
		else
			ft_rotate(stack);
	}
}

void	small_sort_5(t_swap swap)
{
	t_stack	*temp;
	int		index;
	int		val;

	index = 0;
	val = 0;
	temp = *(swap.stack_a);
	while (index < swap.stack_size)
	{
		val = temp -> value;
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
	rev_sort_3(swap.stack_a);
	temp = *(swap.stack_b);
	if (temp -> value < temp -> next -> value)
		ft_swap(swap.stack_b);
	empty_b(swap);
}
