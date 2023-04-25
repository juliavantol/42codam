/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 15:06:45 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/25 13:07:12 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Push every element in stack b to stack a */
void	empty_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = *stack_b;
	while (temp != NULL)
	{
		ft_push(stack_b, stack_a, 'a');
		temp = temp->next;
	}
}

/* Returns the biggest value of the stack */
int	biggest_value(t_stack **stack)
{
	t_stack	*temp;
	int		value;
	int		index;

	temp = *stack;
	value = temp->index;
	index = 0;
	while (temp != NULL)
	{
		if (temp->index > value)
			value = temp->index;
		index++;
		temp = temp->next;
	}
	return (value);
}

/* Sorts a stack of size 3 */
void	sort_3(t_stack **stack)
{
	int		highest;
	t_stack	*head;

	highest = biggest_value(stack);
	head = (*stack);
	if (head->index == highest)
		ft_rotate(stack);
	else if (head->next->index == highest)
		ft_reverse_rotate(stack);
	head = (*stack);
	if (head->index > head->next->index)
		ft_swap(stack, 'a');
}

/* Sorts a stack of size 5 */
void	sort_5(t_ps ps, int index)
{
	t_stack	*temp;

	while (index < ps.arg_len)
	{
		temp = *(ps.stack_a);
		if (temp->index < 2)
		{
			ft_push(ps.stack_a, ps.stack_b, 'b');
			temp = temp->next;
		}
		else
		{
			ft_rotate(ps.stack_a);
			temp = *(ps.stack_a);
		}
		index++;
	}
	if (is_sorted(ps.stack_a) == 0)
		sort_3(ps.stack_a);
	temp = *(ps.stack_b);
	if (temp->index < temp->next->index)
		ft_swap(ps.stack_b, 'b');
	empty_b(ps.stack_a, ps.stack_b);
}
