/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 19:37:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/06/04 21:54:18 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_num(char *input, int index, int num)
{
	int	mtplr;

	mtplr = 1;
	while (index >= 0)
	{
		num += (input[index--] - 48) * mtplr;
		mtplr *= 10;
	}
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
	num = 0;
	len = ft_strlen(input);
	if (len == 0)
		return (0);
	while ((input[start] >= 9 && input[start] <= 13) || input[start] == ' ')
		start++;
	if (input[start] == '-' || input[start] == '+')
	{
		if (input[start] == '-')
			n = -1;
		start++;
	}
	num = get_num(input, len - 1, num) * n;
	return (num);	
}
