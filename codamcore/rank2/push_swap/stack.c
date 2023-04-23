/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 13:59:46 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/22 13:00:44 by juvan-to      ########   odam.nl         */
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

/* Returns last element of the stack */
t_stack	*last_node(t_stack *stack)
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
t_stack	*second_last_node(t_stack *stack)
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
