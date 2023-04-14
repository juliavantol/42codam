/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 17:13:57 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/14 11:09:12 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//make && ./push_swap "87 -487 781 -100 101 0 1"

void	empty_b(t_swap swap)
{
	t_node	*temp;

	temp = *(swap.stack_b);
	while (temp != NULL)
	{
		ft_push(swap.stack_b, swap.stack_a, 'a');
		temp = temp -> next;
	}
}

void	ft_sort(t_swap swap, int i, int j)
{
	t_node	*temp;

	while (i < swap.max_len)
	{	
		j = 0;
		temp = *(swap.stack_a);
		while (j < swap.stack_size)
		{
			if ((temp -> value >> i & 1) == 0)
			{
				ft_push(swap.stack_a, swap.stack_b, 'b');
				free(temp);
				temp = temp -> next;
			}
			else
			{
				ft_rotate(swap.stack_a);
				temp = *(swap.stack_a);
			}
			j++;
		}
		empty_b(swap);
		i++;
	}
}
