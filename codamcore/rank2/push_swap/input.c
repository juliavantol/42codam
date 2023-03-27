/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 15:36:02 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/27 15:36:26 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks(void)
{
	system("leaks push_swap");
}

int	ft_digit_str(char	*str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if ((ft_isdigit(str[index]) == 0 && str[index] != '-') || (str[index] == '-' && index != 0))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		index++;
	}
	return (1);
}

void	check_input(int argc, char	**argv)
{
	int		index;
	char	**args;

	index = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		while (args[index])
		{
			ft_digit_str(args[index]);
			free(args[index]);
			index++;
		}
		free(args);
	}
	else
	{
		index = 1;
		while (argv[index])
			ft_digit_str(argv[index++]);
	}
}
