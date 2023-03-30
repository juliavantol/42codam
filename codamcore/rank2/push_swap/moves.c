/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 16:06:50 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/30 16:27:00 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pop(t_node **stack)
{
	t_node	*last;
	t_node	*temp;

	temp = *stack;
	last = ft_lstnode(*stack);
	free(last);
	last = NULL;
	while (temp -> next -> next != NULL)
		temp = temp -> next;
	temp -> next = NULL;
}

void	ft_pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*last;

	last = ft_lstnode(*stack_a);
	ft_addnode(stack_b, last);
	ft_pop(stack_a);
}
