/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 16:06:50 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/31 14:29:42 by juvan-to      ########   odam.nl         */
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
	ft_addnode(stack_dst, last);
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
	ft_addnode(stack, last);
	ft_addnode(stack, second_last);
}

void	ft_swap_both(t_node **stack_a, t_node **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}

// void	ft_rotate(t_node **stack_a, t_node **stack_b)
// {
// 	int		size;
// 	int		index;
	
// 	if (*stack_a == NULL)
// 		return ;
// 	size = ft_stacksize(*stack_a);
// 	index = 0;
// 	while (index < size)
// 	{
// 		ft_push(stack_a, stack_b);
// 		index++;

// 	}
// 	*stack_a = *stack_b;
// 	*stack_b = NULL;
// }

// void	ft_reverse_rotate(t_node **stack)
// {
// 	t_node	*temp;
// 	t_node	*last;
// 	t_node	*val;
	
// 	if (*stack == NULL)
// 		return ;
// 	temp = *stack;
// 	last = ft_last(*stack);
// 	temp = temp -> next;
// 	while (temp -> next != NULL)
// 	{
// 		val = temp;
// 		printf("%d\n", val -> value);
// 		temp = temp -> next;
// 		// *stack_a = val;
// 	}
// 	val = temp;
// 	printf("%d\n", val -> value);
// 	last = *stack;
// 	// *stack_a = first;
// 	// ft_addnode(stack_a, first);
// }

void	ft_rotate(t_node **stack)
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
}

void	ft_reverse_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*head;
	
	if (*stack == NULL)
		return ;
	last = ft_last(*stack);
	head = *stack;
	*stack = (*stack) -> next;
	head -> next = NULL;
	last -> next = head;
	
}

