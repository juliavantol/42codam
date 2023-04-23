/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_int.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 13:38:42 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/20 18:55:09 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	convert(const char *str, long index, long n)
{
	long	sum;

	sum = 0;
	while (ft_isdigit(str[index]))
		sum = sum * 10 + str[index++] - 48;
	return (sum * n);
}

static long	find_start(const char *str)
{
	long	start;
	long	n;

	start = 0;
	n = 1;
	while ((str[start] >= 9 && str[start] <= 13) || str[start] == ' ')
		start++;
	if (str[start] == '-' || str[start] == '+')
	{
		if (str[start] == '-')
			n = -1;
		start++;
	}
	return (convert(str, start, n));
}

int	ft_atoi_long(const char *str)
{
	long	num;

	if (ft_strlen(str) == 0)
		return (0);
	if (str == NULL)
		return (ft_atoi(str));
	num = find_start(str);
	if (num < -2147483648 || num > 2147483647)
		ft_error();
	return (find_start(str));
}
