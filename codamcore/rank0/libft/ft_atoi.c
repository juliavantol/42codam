/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 13:03:01 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/13 13:31:02 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	index;
	int	multiplier;
	int	sum;

	multiplier = 1;
	index = 0;
	sum = 0;
	while (ft_isdigit(str[index]))
		index++;
	index--;
	while (index > -1)
	{
		sum += (str[index] - 48) * multiplier;
		multiplier *= 10;
		index--;
	}
	return (sum);
}
