/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   anagram.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 12:05:58 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/09 12:11:34 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	anagram(char *a, char *b)
{
	unsigned char *one = (unsigned char *)a;
	unsigned char *two = (unsigned char *)b;
	int	index = 32;
	int ascii[127];

	while (index < 128)
	{
		ascii[index] = 0;
		index++;
	}
	index = -1;
	while (one[++index])
		ascii[one[index]]++;
	index = -1;
	while(two[++index])
		ascii[two[index]]--;
	index = 32;
	while (index < 128)
	{
		if (ascii[index] != 0)
			return (0);
		index++;
	}
	return (1);
}

int	main(void)
{
	printf("%d\n", anagram("hello", "olldeh"));
}
