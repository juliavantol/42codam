/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 14:35:48 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/12 16:20:15 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*top;
	
	if (*stack == NULL)
		return ;
	last = ft_last(*stack);
	top = *stack;
	*stack = (*stack) -> next;
	top -> next = NULL;
	last -> next = top;
	printf("ra\n");
}

void	ft_reverse_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*head;
	t_node	*second_last;
	
	if (*stack == NULL)
		return ;
	last = ft_last(*stack);
	second_last = ft_secondlast(*stack);
	head = *stack;
	*stack = last;
	(*stack)-> next = head;
	second_last -> next = NULL;
	printf("rra\n");
}

void	ft_reverse_rotate_both(t_node **stack_a, t_node **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}

void	ft_rotate_both(t_node **stack_a, t_node **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}