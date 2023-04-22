/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 18:36:00 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/22 10:39:26 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Returns last element of the stack */
t_stack	*ft_last2(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	if (stack != NULL)
	{
		while (last -> next != NULL)
			last = last -> next;
	}
	return (last);
}

/* Adds the node to the stack */
void	ft_add_node2(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack && new)
	{
		last = ft_last2(*stack);
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
t_stack	*ft_make_node3(t_temp input)
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

void	fill_stack2(t_temp *input, t_stack **stack, int arg_len)
{
	int	index;

	index = 0;
	while (index < arg_len)
	{
		ft_add_node2(stack, ft_make_node3(input[index]));
		index++;
	}
}
