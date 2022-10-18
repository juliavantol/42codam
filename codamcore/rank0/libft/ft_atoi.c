/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 13:03:01 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/17 14:15:29 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function converts the initial portion of str to int */

int	ft_atoi(const char *str)
{
	int	index;
	int	multiplier;
	int	sum;

	multiplier = 1;
	index = 0;
	sum = 0;
	while (str[index] != 27 && !(str[index] > 32 && str[index] < 127))
		index++;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (ft_isdigit(str[index]))
		index++;
	index--;
	while (ft_isdigit(str[index]))
	{
		sum += (str[index] - 48) * multiplier;
		multiplier *= 10;
		index--;
	}
	if (str[index] == '-')
		sum *= -1;
	return (sum);
}
