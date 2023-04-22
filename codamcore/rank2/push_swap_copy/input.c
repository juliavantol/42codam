/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 15:36:02 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/06 13:16:17 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks(void)
{
	system("leaks push_swap");
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

/* Checks whether the input only contains digits */
char	**check_input(int argc, char	**argv, int	*arg_len)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		while (args[(*arg_len)])
			ft_digit_str(args[(*arg_len)++]);
		return (args);
	}
	else
	{
		(*arg_len)++;
		while (argv[(*arg_len)])
			ft_digit_str(argv[(*arg_len)++]);
		(*arg_len)--;
		return (&argv[1]);
	}
	return (NULL);
}
