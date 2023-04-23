/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 15:30:41 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/22 13:31:31 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks()
{
	system("leaks push_swap");
}

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

void	check_duplicates(t_temp	*stack, int arg_len)
{
	int		i;
	int		j;

	i = 0;
	while (i < arg_len)
	{
		j = 0;
		while (j < arg_len)
		{
			if (i != j && stack[i].value == stack[j].value)
				ft_error();
			j++;
		}
		i++;
	}
}

/* Checks if there are only digits in the string */
int	ft_digit_str(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((ft_isdigit(str[i]) == 0 && str[i] != '-' && str[i] != '+')
			|| ((str[i] == '-' || str[i] == '+') && i != 0))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return (1);
}