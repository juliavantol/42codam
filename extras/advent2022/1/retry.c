/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   retry.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 15:27:26 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/12/01 17:34:12 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* gcc -Wall -Wextra -Werror retry.c -o retry && ./retry
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	FILE	*file;
	int		num_array[2020];
	char	temp[100];
	int		i = 0;
	int		sum = 0;
	int j, a, n;
	int first = 0;
	int second = 0;
	int third = 0;

	file = fopen("input.txt", "r");
	while (1)
	{
		if (strncmp(temp, "\n", 1) == 0)
		{
			num_array[i] = sum;
			i++;
			sum = 0;
		}
		else
			sum += atoi(temp);
		if (!(fgets(temp, 100, file)))
		{
			num_array[i] = sum;
			i++;
			break ;
		}
	}
	num_array[i] = '\0';
	n = 0;
	for (int x = 0; x < i; ++x) 
	{
		 for (j = x + 1; j < i; ++j) 
		{
			if (num_array[x] < num_array[j]) 
			{
				a = num_array[x];
				num_array[x] = num_array[j];
				num_array[j] = a;
			}
		}
	}
	first = num_array[0];
	second = num_array[1];
	third = num_array[2];
	printf("%d + %d + %d = %d\n", first, second, third, first + second + third);
	fclose(file);
}