/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 15:30:41 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/24 17:47:41 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Prints an error message and exits */
void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

/* Checks if there are only digits in the string */
int	ft_digit_str(char *str)
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

/* Checks if the stack is sorted */
int	is_sorted(t_stack **stack)
{
	t_stack	*temp;
	int		value;
	int		prev_value;

	temp = *stack;
	prev_value = temp->value;
	value = prev_value;
	while (temp != NULL)
	{
		value = temp->value;
		if (prev_value > value)
			return (0);
		prev_value = temp->value;
		temp = temp->next;
	}
	return (1);
}
