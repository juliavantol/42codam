/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 13:03:01 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/25 12:29:46 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function converts the initial portion of str to int */
static int	convert(const char *str, int index, int n);
static int	check_start(const char *str);

static int	check_start(const char *str)
{
	int	start;
	int	n;

	start = 0;
	n = 1;
	while ((str[start] >= 9 && str[start] <= 13) || str[start] == ' ')
		start++;
	if (str[start] == '-' || str[0] == '-')
	{
		n = -1;
		start++;
	}
	else if (str[start] == '+' || str[0] == '+')
		start++;
	return (convert(str, start, n));
}

static int	convert(const char *str, int index, int n)
{
	int	sum;

	sum = 0;
	while (ft_isdigit(str[index]))
		sum = sum * 10 + str[index++] - 48;
	return (sum * n);
}

int	ft_atoi(const char *str)
{
	int	sum;

	sum = 0;
	if (str == NULL || ft_strlen(str) == 0)
		return (0);
	sum = check_start(str);
	return (sum);
}


// int	ft_atoi(const char *str)
// {
// 	int	index;
// 	int	multiplier;
// 	int	sum;

// 	multiplier = 1;
// 	index = 0;
// 	sum = 0;
// 	if (strlen(str) == 1 && ft_isdigit(str[index]))
// 		return (str[index] - 48);
// 	while (str[index] != 27 && !(str[index] > 32 && str[index] < 127))
// 		index++;
// 	if (str[index] == '-' || str[index] == '+')
// 		index++;
// 	while (ft_isdigit(str[index]))
// 		index++;
// 	index--;
// 	while (ft_isdigit(str[index]))
// 	{
// 		sum += (str[index] - 48) * multiplier;
// 		multiplier *= 10;
// 		index--;
// 	}
// 	if (str[index] == '-')
// 		sum *= -1;
// 	// printf("%d\n", index);
// 	return (sum);
// }