/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 16:06:50 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/31 16:43:37 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_push_node(t_node **stack, t_node *new)
{
	t_node	*second;

	if (!new)
		return ;
	if (*stack)
	{
		second = *stack;
		*stack = new;
		new -> next = second;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

// Take the top value from SRC and puts it into DST
void	ft_push(t_node **stack_src, t_node **stack_dst)
{
	t_node	*new;
	t_node	*second;
	int		temp;

	if (*stack_src == NULL)
		return ;
	temp = (*stack_src) -> value;
	second = (*stack_src) -> next;
	new = ft_make_node(temp);
	ft_push_node(stack_dst, new);
	(*stack_src) = second;
}

t_node	*ft_pop(t_node **stack)
{
	t_node	*temp;
	t_node	*last;

	temp = *stack;
	if (temp -> next == NULL)
	{
		*stack = NULL;
		return (*stack);
	}
	last = ft_last(*stack);
	while (temp -> next -> next != NULL)
		temp = temp -> next;
	temp -> next = NULL;
	return (last);
}

/* Swap top two elements from stack */
void	ft_swap(t_node **stack)
{
	t_node	*second;
	t_node	*third;

	if (*stack == NULL || (*stack) -> next == NULL)
		return ;
	second = (*stack) -> next;
	third = (*stack) -> next -> next;
	(*stack) -> next = third;
	second -> next = (*stack);
	(*stack) = second;
}

void	ft_swap_both(t_node **stack_a, t_node **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}
