/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 17:13:57 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/25 14:42:44 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Returns the binary length of the max digit */
int	max_digit(int max_num)
{
	int	index;

	index = 0;
	max_num--;
	while (max_num >> index != 0)
		index++;
	return (index);
}

/* Sorts a big stack using radix sort */
void	sort_big(t_ps ps, int i, int j, int max_digit)
{
	t_stack	*temp;

	while (i < max_digit)
	{	
		j = 0;
		while (j < ps.arg_len)
		{
			temp = *(ps.stack_a);
			if ((temp->index >> i & 1) == 0)
				ft_push(ps.stack_a, ps.stack_b, 'b');
			else
				ft_rotate(ps.stack_a);
			j++;
		}
		while (stack_size(*(ps.stack_b)) != 0)
			ft_push(ps.stack_b, ps.stack_a, 'a');
		i++;
	}
}
