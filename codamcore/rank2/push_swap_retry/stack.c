/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 13:59:46 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/25 13:07:26 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Returns new node */
t_stack	*new_node(int value, int index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		exit (1);
	node->value = value;
	node->index = index;
	node->next = NULL;
	return (node);
}

/* Adds the node from the input to the end of stack */
void	add_node(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack && new)
	{
		last = last_node(*stack);
		last->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

/* Returns size of stack */
int	stack_size(t_stack *stack)
{
	t_stack	*temp;
	int		count;

	temp = stack;
	count = 0;
	while (temp != NULL)
	{
		temp = temp->next;
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
		while (temp->next != NULL)
			temp = temp->next;
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
		while (temp->next != NULL && temp->next->next != NULL)
			temp = temp->next;
	}
	return (temp);
}
