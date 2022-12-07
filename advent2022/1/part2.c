/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   part2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 15:27:26 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/12/01 17:08:49 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* gcc -Wall -Wextra -Werror part2.c -o run2 && ./run2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	FILE	*file;
	// int		sum = 0;
	int		num_array[2020];
	char	temp[100];
	int		i = 0;

	file = fopen("text.txt", "r");
	while(fgets(temp, 100, file))
	{
    	printf("%s\n", temp);
	}
	num_array[i] = '\0';
	fclose(file);
}

// int	main(void)
// {
// 	FILE	*file;
// 	int		sum = 0;
// 	int		first = 0;
// 	int		second = 0;
// 	int		third = 0;
// 	char	temp[20];

// 	file = fopen("input.txt", "r");
// 	while (1)
// 	{
// 		if (strncmp(temp, "\n", 1) == 0)
// 		{
// 			if (sum > first)
// 			{
// 				if (third < second)
// 					third = second;
// 				if (second < first)
// 					second = first;
// 				first = sum;
// 			}
// 			else
// 			{
// 				if (sum > second)
// 				{
// 					third = second;
// 					second = sum;
// 				}
// 				else if (sum > third)
// 					third = sum;
// 			}
// 			printf("1: %d, 2:%d, 3:%d\n\n", first, second, third);
// 			sum = 0;
// 		}
// 		else
// 			sum += atoi(temp);
// 		if (!(fgets(temp, 20, file)))
// 		{
// 			if (sum > first)
// 				first = sum;
// 			if (sum > second)
// 				second = sum;
// 			if (sum > third)
// 				third = sum;
// 			break ;
// 		}
// 	}
// 	printf("%d + %d + %d = %d\n", first, second, third, first + second + third);
// 	fclose(file);
// }

// /* 207273 */