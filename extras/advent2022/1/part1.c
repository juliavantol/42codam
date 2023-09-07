/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   part1.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 15:27:26 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/12/01 15:56:01 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* gcc -Wall -Wextra -Werror part1.c -o run1 && ./run1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	FILE	*file;
	int		sum = 0;
	int		highest = 0;
	char	temp[20];

	file = fopen("input.txt", "r");
	while (fgets(temp, 20, file))
	{
		if (strncmp(temp, "\n", 1) == 0)
			sum = 0;
		else
			sum += atoi(temp);
		if (sum > highest)
			highest = sum;
	}
	printf("highest: %d\n", highest);
	fclose(file);
}
