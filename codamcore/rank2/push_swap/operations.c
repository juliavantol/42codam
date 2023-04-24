/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 16:06:50 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/24 12:58:47 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Take the top value from SRC and puts it into DST
void	ft_push(t_stack **src, t_stack **dst, char name)
{
	t_stack	*node;
	t_stack	*temp;

	if (*src == NULL)
		exit(1);
	temp = (*src)->next;
	node = new_node((*src)->value, (*src)->index);
	(*src) = temp;
	if (*dst)
	{
		temp = *dst;
		*dst = node;
		node->next = temp;
	}
	else
	{
		*dst = node;
		(*dst)->next = NULL;
	}
	if (name == 'a')
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}

/* Swap top two elements from stack */
void	ft_ps(t_stack **stack, char c)
{
	t_stack	*second;
	t_stack	*third;

	if (*stack == NULL || (*stack)->next == NULL)
		exit(1);
	second = (*stack)-> next;
	third = (*stack)-> next->next;
	(*stack)-> next = third;
	second->next = (*stack);
	(*stack) = second;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

/* Rotate the stack so that the first node becomes the last */
void	ft_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*top;

	if (*stack == NULL)
		return ;
	last = last_node(*stack);
	top = *stack;
	*stack = (*stack)->next;
	top->next = NULL;
	last->next = top;
	ft_putstr_fd("ra\n", 1);
}

/* Rotate the stack so that the last node becomes the first */
void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*head;
	t_stack	*second_last;

	if (*stack == NULL)
		return ;
	last = last_node(*stack);
	second_last = second_last_node(*stack);
	head = *stack;
	*stack = last;
	(*stack)-> next = head;
	second_last->next = NULL;
	ft_putstr_fd("rra\n", 1);
}
