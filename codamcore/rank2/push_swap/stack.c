/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 13:59:46 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/31 13:52:51 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_node *lst)
{
	t_node	*temp;
	int		count;

	temp = lst;
	count = 0;
	while (temp != NULL)
	{
		temp = temp -> next;
		count++;
	}
	return (count);
}

t_node	*ft_newnode(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node -> value = num;
	node -> next = NULL;
	return (node);
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
		while (temp -> next != NULL && temp -> next -> next != NULL)
			temp = temp -> next;
	}
	return (temp);
}

void	ft_addnode(t_node **stack, t_node *new)
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

void	fill_stack(char	**input, t_node **stack)
{
	int		index;
	int		num;

	index = 0;
	while (input[index])
	{
		num = ft_atoi(input[index]);
		ft_addnode(stack, ft_newnode(num));
		index++;
	}
}
