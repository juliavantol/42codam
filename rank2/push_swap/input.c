/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 18:21:56 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/24 20:15:43 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Frees the temp input */
void	*free_temp(char	**temp)
{
	size_t	index;

	index = 0;
	while (temp[index])
		free(temp[index++]);
	free(temp);
	return (NULL);
}

/* Get index from element by counting how many elements are smaller */
int	get_index(t_stack **stack, int num)
{
	int		place;
	t_stack	*temp;

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

/* Simplify the numbers in the stack and check for duplicates */
void	index_stack(t_stack **stack_a, int size)
{
	t_stack	*temp;
	int		*dups;
	int		index;

	temp = *stack_a;
	dups = malloc(size * sizeof(int));
	if (!dups)
		exit (1);
	index = 0;
	while (index < size)
		dups[index++] = 0;
	index = 0;
	while (temp)
	{
		index = get_index(stack_a, temp -> value);
		if (dups[index] > 0)
			ft_error();
		dups[index]++;
		temp -> index = index;
		temp = temp -> next;
	}
	free(dups);
}

/* Puts the input in the stack */
void	handle_input(t_stack **stack_a, char **argv)
{
	char	**temp;
	int		index;

	argv++;
	temp = NULL;
	while (*argv)
	{
		if (if_empty(*argv) == 1)
			ft_error();
		if (ft_strchr(*argv, ' '))
		{
			temp = ft_split(*argv, ' ');
			index = 0;
			while (temp[index])
				add_node(stack_a, new_node(ft_atoi_max(temp[index++]), -1));
			temp = free_temp(temp);
		}
		else
			add_node(stack_a, new_node(ft_atoi_max(*argv), -1));
		argv++;
	}
	if (is_sorted(stack_a) == 1)
		exit (1);
	index_stack(stack_a, stack_size(*stack_a));
}
