/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   biggest_pal.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 11:02:41 by Julia         #+#    #+#                 */
/*   Updated: 2023/01/27 15:10:20 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	int len = ft_strlen(str);
	int	i = 0;
	int left, right;
	int max = 0;
	int start = 0;

	// Loop through whole string
	while (i < len)
	{
		left = i - 1;
		right = i + 1;
		// Check for big palindrome of the same characters
		while (left >= 0 && str[left] == str[i])
			left--;
		while (right < len && str[right] == str[i])
			right++;
		// Now keep incrementing and checking if the sides are matching
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

int	main(int argc, char **argv)
{
	if (argc == 2)
		biggest_pal(argv[1]);
	write(1, "\n", 1);
	return (0);
}