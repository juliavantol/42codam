/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 13:59:46 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/20 18:41:49 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/* Creates a new node */
t_stack	*ft_make_node2(int num)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		exit (1);
	node -> value = num;
	node -> next = NULL;
	return (node);
}

/* Creates a new node */
t_stack	*ft_make_node(int num)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		exit (1);
	node -> value = num;
	node -> next = NULL;
	return (node);
}

/* Adds the node to the stack */
void	ft_add_node(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack && new)
	{
		last = ft_last(*stack);
		last -> next = new;
		new -> next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

/* Returns last element of the stack */
t_stack	*ft_last(t_stack *stack)
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
t_stack	*ft_secondlast(t_stack *stack)
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
