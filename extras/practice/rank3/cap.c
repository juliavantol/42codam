/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cap.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 22:10:24 by Julia         #+#    #+#                 */
/*   Updated: 2023/06/03 17:11:30 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

// gcc -Wall -Wextra -Werror cap.c -o cap && ./cap "hello" "xx"
// gcc -Wall -Wextra -Werror cap.c -o cap && ./cap "     hello     " "xx"
// gcc -Wall -Wextra -Werror cap.c -o cap && ./cap "hello        there"

int	format_word(char *str, int start)
{
	int end = start;
	int temp;

	while (str[end + 1] && str[end + 1] != ' ' && str[end + 1] != '\t' && str[end + 1] != '\n')
	{
		if (str[end] >= 'A' && str[end] <= 'Z')
		{
			temp = str[end] + 32;
			write(1, &temp, 1);
		}	
		else
			write(1, &str[end], 1);
		end++;
	}
	if (str[end] >= 'a' && str[end] <= 'z')
	{
		temp = str[end] - 32;
		write(1, &temp, 1);
	}
	else if (str[end] >= 'A' && str[end] <= 'Z')
		write(1, &str[end], 1);
	return (++end);
}

int main (int argc, char **argv)
{
	int i = 1;
	int index = 0;
	char *temp = NULL;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[i])
	{
		temp = argv[i];
		index = 0;
		while (temp[index])
		{
			if (temp[index] == '\t' || temp[index] == ' ' || temp[index] == '\n')
				write(1, &temp[index++], 1);
			else
				index = format_word(temp, index);
		}
		temp = NULL;
		write(1, "\n", 1);
		i++;
	}
}
