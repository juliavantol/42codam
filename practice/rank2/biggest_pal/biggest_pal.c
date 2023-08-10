/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   biggest_pal.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 11:50:38 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/09 11:58:44 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"

int	ft_strlen(char *str)
{
	int	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

void print_sub(char *str, int start, int end)
{
	while (start < end)
	{
		write(1, &str[start], 1);
		start++;
	}
}

void biggest_pal(char *str)
{
	int	i = 0;
	int left, right;
	int max = 0;
	int start = 0;
	int len = ft_strlen(str);

	while (i < len)
	{
		left = i - 1;
		right = i + 1;
		while (left >= 0 && str[left] == str[i])
			left--;
		while (right < len && str[right] == str[i])
			right++;
		while (str[left] == str[right] && left >= 0 && right < len)
		{
			left--;
			right++;
		}
		if ((right - left - 1) >= max)
		{
			max = right - left - 1;
			start = left + 1;
		}
		i++;
	}
	print_sub(str, start, max + start);
}

int	main(void)
{
	biggest_pal("abbdddakhgfduirdv");
}
