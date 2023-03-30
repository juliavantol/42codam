/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 13:59:46 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/30 12:43:47 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_node	*ft_lstnode(t_node *lst)
{
	t_node	*temp;

	temp = lst;
	if (lst != NULL)
	{
		while (temp -> next != NULL)
			temp = temp -> next;
	}
	return (temp);
}

void	ft_addnode(t_node **stack, t_node *new)
{
	t_node	*last;

	ft_lstnode(*stack);
	if (*stack != NULL && new != NULL)
	{
		last = ft_lstnode(*stack);
		last -> next = new;
	}
	else
		*stack = new;
	last = new;
}
