/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 13:59:46 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/23 23:18:37 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Adds the node from the input to the end of stack */
void	add_node(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack && new)
	{
		last = last_node(*stack);
		last -> next = new;
		new -> next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

/* Returns size of stack */
int	ft_stacksize(t_stack *stack)
{
	t_stack	*temp;
	int		count;

	temp = stack;
	count = 0;
	while (temp != NULL)
	{
		temp = temp -> next;
		count++;
	}
	return (count);
}

/* Returns last element of the stack */
t_stack	*last_node(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (stack != NULL)
	{
		while (temp -> next != NULL)
			temp = temp -> next;
	}
	return (temp);
}

/* Returns second to last element of the stack */
t_stack	*second_last_node(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (stack != NULL)
	{
		while (temp -> next != NULL && temp -> next->next != NULL)
			temp = temp -> next;
	}
	return (temp);
}
