/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   duplicates.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 12:23:19 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/17 17:01:56 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dups(t_value	*indexed_nums, int arg_len)
{
	int		i;
	int		j;

	i = 0;
	while (i < arg_len)
	{
		j = 0;
		while (j < arg_len)
		{
			if (i != j && indexed_nums[i].value == indexed_nums[j].value)
			{
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
