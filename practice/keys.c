/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 12:31:58 by Julia         #+#    #+#                 */
/*   Updated: 2023/01/27 15:09:47 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	is_anagram(char *a, char *b)
{
	unsigned char *one = (unsigned char *)a;
	unsigned char *two = (unsigned char *)b;
	int	i = 32;
	int	symbols[127];

	while (i < 128)
	{
		symbols[i] = 0;
		i++;
	}
	i = -1;
	while (one[++i])
		symbols[one[i]]++;
	i = -1;
	while (two[++i])
		symbols[two[i]]--;
	i = 32;
	while (i < 128)
	{
		if (symbols[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

// int	main(void)
// {
// 	time_t begin = time(NULL);

// 	printf("%d\n", is_anagram(".123?.", "?321.."));

// 	time_t end = time(NULL);
// 	printf("Running time: %ld seconds\n", end - begin);	
// }

void	print_sub(char *str, int start, int end)
{
	while (start < end)
		write(1, &str[start++], 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void biggest_pal(char *str)
{
	int	left;
	int right;
	int	len = ft_strlen(str);
	int	max = 1;
	int start = 0;
	int index = 0;
	
	start++;
	while (index < len)
	{
		left = index - 1;
		right = index + 1;
		while (right < len && str[right] == str[index])
			right++;
		while (left >= 0 && str[left] == str[index])
			left--;
		while (left >= 0 && right < len && str[left] == str[right])
		{
			left--;
			right++;
		}
		if ((right - left - 1) >= max)
		{
			max = right - left - 1;
			start = left + 1;
		}
		index++;
	}
	print_sub(str, start, max + start);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		biggest_pal(argv[1]);	
// 	}
// 	print_sub("\n", 0, 1);
// }