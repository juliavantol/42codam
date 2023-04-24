/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 17:13:57 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/24 14:25:55 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Push every element in stack b to stack a */
void	empty_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = *stack_b;
	while (temp != NULL)
	{
		ft_push(stack_b, stack_a, 'a');
		free(temp);
		temp = temp->next;
	}
}

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
		temp = *(ps.stack_a);
		while (j < ps.arg_len)
		{
			if ((temp->index >> i & 1) == 0)
			{
				ft_push(ps.stack_a, ps.stack_b, 'b');
				free(temp);
				temp = temp->next;
			}
			else
			{
				ft_rotate(ps.stack_a);
				temp = *(ps.stack_a);
			}
			j++;
		}
		empty_b(ps.stack_a, ps.stack_b);
		i++;
	}
}
