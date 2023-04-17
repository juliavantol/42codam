/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_stack.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 16:11:56 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/17 17:51:17 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack2(t_stack2 *head, int count)
{
	t_stack2	*temp;
	int			i;

	temp = head;
	i = 0;
	while (i < count)
	{
		printf("value: %d original i: %d new i: %d\n", temp -> value, temp->original_position, temp->new_position);
		temp = temp -> next;
		i++;
	}
}

/* Adds the node to the stack */
void	add_node(t_stack2 **stack, t_stack2 *new)
{
	t_stack2	*last;

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

/* Creates a new entry for the stack */
t_stack2	*new_node(int value, int position)
{
	t_stack2	*node;

	node = malloc(sizeof(t_stack2));
	if (node == NULL)
		exit (1);
	node -> value = value;
	node -> original_position = position;
	node -> new_position = -1;
	node -> next = NULL;
	return (node);
}

/* Returns last element of the stack */
t_stack2	*last_node(t_stack2 *stack)
{
	t_stack2	*temp;

	temp = stack;
	if (stack != NULL)
	{
		while (temp -> next != NULL)
			temp = temp -> next;
	}
	return (temp);
}