/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 16:06:50 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/30 16:53:04 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pop(t_node **stack)
{
	t_node	*temp;

	temp = *stack;
	if (temp -> next == NULL)
	{
		*stack = NULL;
		return ;
	}
	else
	{
		while (temp -> next -> next != NULL)
			temp = temp -> next;
	}
	temp -> next = NULL;
}

// Take the top value form A and puts it into B
void	ft_push(t_node **stack_src, t_node **stack_dst)
{
	t_node	*last;

	if (*stack_src == NULL)
		return ;
	last = ft_lstnode(*stack_src);
	ft_addnode(stack_dst, last);
	ft_pop(stack_src);
}
