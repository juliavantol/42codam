/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 14:35:48 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/17 15:47:25 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*top;
	
	if (*stack == NULL)
		return ;
	last = ft_last(*stack);
	top = *stack;
	*stack = (*stack) -> next;
	top -> next = NULL;
	last -> next = top;
	ft_putstr_fd("ra\n", 1);
}

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*head;
	t_stack	*second_last;
	
	if (*stack == NULL)
		return ;
	last = ft_last(*stack);
	second_last = ft_secondlast(*stack);
	head = *stack;
	*stack = last;
	(*stack)-> next = head;
	second_last -> next = NULL;
	ft_putstr_fd("rra\n", 1);
}
