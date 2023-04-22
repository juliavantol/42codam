/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   duplicates.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 12:23:19 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/13 12:36:06 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dups(t_value	*indexed_nums, int arg_len)
{
	int		index;
	int		temp;
	int		*dups;

	index = 0;
	dups = malloc(arg_len * sizeof(int));
	while (index < arg_len)
		dups[index++] = 0;
	index = 0;
	while (index < arg_len)
	{
		temp = indexed_nums[index].value;
		if (dups[temp] == 1)
		{
			free(dups);
			printf("Error\n");
			exit(1);
		}
		else
			dups[temp] = 1;	
		index++;
	}
	free(dups);
}
