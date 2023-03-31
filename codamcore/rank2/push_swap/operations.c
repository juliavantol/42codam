/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 16:06:50 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/31 14:46:11 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Take the top value from SRC and puts it into DST
void	ft_push(t_node **stack_src, t_node **stack_dst)
{
	t_node	*last;

	if (*stack_src == NULL)
		return ;
	last = ft_last(*stack_src);
	ft_add_node(stack_dst, last);
	ft_pop(stack_src);
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

void	ft_swap(t_node **stack)
{
	t_node	*temp;
	t_node	*last;
	t_node	*second_last;

	temp = *stack;
	if (*stack == NULL || temp -> next == NULL)
		return ;
	last = ft_pop(stack);
	second_last = ft_pop(stack);
	ft_add_node(stack, last);
	ft_add_node(stack, second_last);
}

void	ft_swap_both(t_node **stack_a, t_node **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}
