/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 15:30:41 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/22 11:37:43 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_digit(int max_num)
{
	int	index;

	index = 0;
	max_num--;
	while (max_num >> index != 0)
		index++;
	return (index);
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

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
			ft_error();
		}
		else
			dups[temp] = 1;	
		index++;
	}
	free(dups);
}

/* Checks if there are only digits in the string */
int	ft_digit_str(char	*str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if ((ft_isdigit(str[index]) == 0 && str[index] != '-')
			|| (str[index] == '-' && index != 0))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		index++;
	}
	return (1);
}