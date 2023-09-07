/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day1.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 14:24:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/12/01 15:12:53 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


/* gcc -Wall -Wextra -Werror day1.c -o run1 && ./run1 */
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	FILE	*file;
	int		i;
	int		num_array[2020];
	int		temp;
	int		count;
	int		check;

	i = 0;
	file = fopen("input.txt", "r");
	check = 1;
	while (check == 1)
		check = fscanf(file, "%d,", &num_array[i++]);
	num_array[i - 1] = '\0';
	temp = num_array[0];
	count = 0;
	i = 0;
	while (num_array[i])
	{
		if (num_array[i] > temp)
			count++;
		temp = num_array[i];
		printf("%d\n", temp);
		i++;
	}
	printf("count: %d\n", count);
	fclose(file);
}
