/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 19:37:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/06/06 12:08:19 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	get_num(char *input, int index, int max)
{
	int		mtplr;
	long	num;

	mtplr = 1;
	num = 0;
	while (input[index] && is_digit(input[index]) == 0)
		index--;
	while (index >= 0 && index >= max)
	{
		if (is_digit(input[index]) == 0)
			return (0);
		num += (input[index--] - 48) * mtplr;
		mtplr *= 10;
	}
	if (num < -2147483648 || num > 2147483647)
		return (-1);
	return (num);
}

int	ft_atoi(char *input)
{
	int	num;
	int	len;
	int	start;
	int	n;

	start = 0;
	n = 1;
	len = ft_strlen(input);
	if (len == 0)
		return (0);
	if (len > 19)
		return (-1);
	while ((input[start] >= 9 && input[start] <= 13) || input[start] == ' ')
		start++;
	while (input[start] == '-' || input[start] == '+')
	{
		if (input[start] == '-')
			n = -1;
		start++;
	}
	num = get_num(input, len - 1, start) * n;
	return (num);
}
