/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 16:06:50 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/17 15:47:14 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Pushes node to the stack */
void	ft_push_node(t_stack **stack, t_stack *new)
{
	t_stack	*second;

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
void	ft_push(t_stack **stack_src, t_stack **stack_dst, char name)
{
	t_stack	*node;
	t_stack	*second;
	int		temp;

	if (*stack_src == NULL)
		exit(1);
	temp = (*stack_src) -> value;
	second = (*stack_src) -> next;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		exit (1);
	node -> value = temp;
	node -> next = NULL;
	ft_push_node(stack_dst, node);
	(*stack_src) = second;
	if (name == 'a')
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}

/* Swap top two elements from stack */
void	ft_swap(t_stack **stack)
{
	t_stack	*second;
	t_stack	*third;

	if (*stack == NULL || (*stack) -> next == NULL)
		exit(1);
	second = (*stack)-> next;
	third = (*stack)-> next -> next;
	(*stack)-> next = third;
	second -> next = (*stack);
	(*stack) = second;
	ft_putstr_fd("sa\n", 1);
}