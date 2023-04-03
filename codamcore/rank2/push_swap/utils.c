/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 15:30:41 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/03 15:45:41 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_digits(int n)
{
	int		count;

	count = 1;
	if (n < 0)
	{
		n *= -1;
		count++;	
	}
	while (n >= 10)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

int	max_digit(t_node	*stack)
{
	int		max_len;
	int		index;
	t_node	*temp;
	int		num;
	int		len;

	temp = stack;
	if (stack == NULL)
		return (0);
	max_len = 0;
	index = 0;
	while (temp != NULL)
	{
		num = temp -> value;
		len = count_digits(num);
		if (len > max_len)
			max_len = len;
		temp = temp -> next;
	}
	return (max_len);	
}
