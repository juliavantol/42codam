/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 18:36:00 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/22 13:16:48 by juvan-to      ########   odam.nl         */
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

/* Creates a new node */
t_stack	*make_node(t_temp input)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		exit (1);
	node -> value = input.value;
	node -> index = input.new_position;
	node -> next = NULL;
	return (node);
}

/* Fills the stack with the input */
void	fill_stack(t_temp *input, t_stack **stack, int arg_len)
{
	int	index;

	index = 0;
	while (index < arg_len)
	{
		add_node(stack, make_node(input[index]));
		index++;
	}
}
