/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 17:13:57 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/22 13:10:55 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_b(t_swap swap)
{
	t_stack	*temp;

	temp = *(swap.stack_b);
	while (temp != NULL)
	{
		ft_push(swap.stack_b, swap.stack_a, 'a');
		temp = temp -> next;
	}
}

void	sort_big(t_swap swap, int i, int j, int arg_len)
{
	t_stack	*temp;

	swap.max_len = max_digit(arg_len);
	while (i < swap.max_len)
	{	
		j = 0;
		temp = *(swap.stack_a);
		while (j < arg_len)
		{
			if ((temp -> index >> i & 1) == 0)
			{
				ft_push(swap.stack_a, swap.stack_b, 'b');
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
