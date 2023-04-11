/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 17:13:57 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/11 13:52:26 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//make && ./push_swap "87 -487 781 -100 101 0 1"

void	ft_sort(int max_len, t_node **stack_a, t_node **stack_b)
{
	int		index;
	int		index2;
	int		stack_size;
	t_node	*temp;

	stack_size = ft_stacksize(*stack_a);
	index = 0;
	while (index < max_len)
	{	
		index2 = 0;
		temp = *stack_a;
		while (index2 < stack_size)
		{
			if ((temp -> value >> index & 1) == 0)
			{
				ft_push(stack_a, stack_b);
				temp = temp -> next;
			}
			else
			{
				ft_rotate(stack_a);
				temp = *stack_a;
			}
			index2++;
		}
		index++;
	
	}
}
