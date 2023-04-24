/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 15:06:45 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/24 12:58:22 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_ps(stack, 'a');
}

/* Sorts a stack of size 5 */
void	sort_5(t_stack **stack_a, t_stack **stack_b, int arg_len, int value)
{
	t_stack	*temp;
	int		index;

	index = 0;
	temp = *stack_a;
	while (index < arg_len)
	{
		value = temp -> index;
		if (value < 2)
		{
			ft_push(stack_a, stack_b, 'b');
			temp = temp->next;
		}
		else
		{
			ft_rotate(stack_a);
			temp = *(stack_a);
		}
		index++;
	}
	if (is_sorted(stack_a) == 0)
		sort_3(stack_a);
	if ((*(stack_b))->index < (*(stack_b))->next->index)
		ft_ps(stack_b, 'b');
	empty_b(stack_a, stack_b);
}
