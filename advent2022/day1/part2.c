/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   part2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 14:24:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/12/01 15:20:05 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


/* gcc -Wall -Wextra -Werror part2.c -o run2 && ./run2 */
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	FILE	*file;
	int		i = 0;
	int		num_array[2020];
	int		temp;
	int		count = 0;
	int		check = 1;

	file = fopen("input.txt", "r");
	while (check == 1)
		check = fscanf(file, "%d,", &num_array[i++]);
	num_array[i - 1] = '\0';
	i = 0;
	temp = num_array[i] + num_array[i + 1] + num_array[i + 2];
	while (num_array[i] && num_array[i + 1] && num_array[i + 2])
	{
		if (num_array[i] + num_array[i + 1] + num_array[i + 2] > temp)
			count++;
		temp = num_array[i] + num_array[i + 1] + num_array[i + 2];
		i++;
	}
	printf("count: %d\n", count);
	fclose(file);
}
