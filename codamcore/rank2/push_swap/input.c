/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 18:21:56 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/23 23:24:59 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack **stack, int num)
{
	int		place;
	t_stack *temp;

	place = 0;
	temp = *stack;
	while (temp)
	{
		if (temp -> value < num)
			place++;
		temp = temp -> next;
	}
	return (place);
}

void	index_stack(t_swap swap)
{
	t_stack *temp;
	int		size;
	int		*dups;
	int		index;

	temp = *(swap.stack_a);
	size = ft_stacksize(*(swap.stack_a));
	dups = malloc(size * sizeof(int));
	if (!dups)
		exit (1);
	index = 0;
	while (index < size)
		dups[index++] = 0;
	index = 0;
	while (temp)
	{
		index = get_index(swap.stack_a, temp -> value);
		if (dups[index] > 0)
			ft_error();
		dups[index]++;
		temp -> index = index;
		temp = temp -> next;
	}
}

void	add_to_stack(t_swap swap, char *str)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		exit (1);
	node -> value = ft_atoi_long(str);
	node -> index = -1;
	node -> next = NULL;
	add_node(swap.stack_a, node);
}

void	handle_input(t_swap swap, char **argv, int *arg_len)
{
	char	**temp;

	argv++;
	while (*argv)
	{
		if (ft_strchr(*argv, ' '))
		{
			temp = ft_split(*argv, ' ');
			while (*temp)
			{
				add_to_stack(swap, *temp++);
				(*arg_len)++;
			}
		}
		else
		{
			add_to_stack(swap, *argv);
			(*arg_len)++;
		}
		argv++;
	}
	index_stack(swap);
}
