/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 13:59:46 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/31 14:50:32 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_node *stack)
{
	t_node	*temp;
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

void	fill_stack(char	**input, t_node **stack)
{
	int		index;
	int		num;

	index = 0;
	while (input[index])
	{
		num = ft_atoi(input[index]);
		ft_add_node(stack, ft_make_node(num));
		index++;
	}
}

t_node	*ft_make_node(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node -> value = num;
	node -> next = NULL;
	return (node);
}

void	ft_add_node(t_node **stack, t_node *new)
{
	t_node	*last;

	if (*stack && new)
	{
		last = ft_last(*stack);
		last -> next = new;
		new -> next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

t_node	*ft_last(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	if (stack != NULL)
	{
		while (temp -> next != NULL)
			temp = temp -> next;
	}
	return (temp);
}

t_node	*ft_secondlast(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	if (stack != NULL)
	{
		while (temp -> next != NULL && temp -> next->next != NULL)
			temp = temp -> next;
	}
	return (temp);
}
