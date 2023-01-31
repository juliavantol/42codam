/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   anagram.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 12:31:58 by Julia         #+#    #+#                 */
/*   Updated: 2023/01/27 12:17:20 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int        is_anagram(char *a, char *b)
{
	unsigned char	*one = (unsigned char *)a;
	unsigned char	*two = (unsigned char *)b;
	int				index = 32;
	int				chart[127];
	
	while (index < 128)
	{
		chart[index] = 0;
		index++;
	}
	index = -1;
	while (one[++index])
		chart[one[index]]++;
	index = -1;
	while (two[++index])
		chart[two[index]]--;
	index = 32;
	while (index < 128)
	{
		if (chart[index] != 0)
			return (0);	
		index++;
	}
	return (1);
}

int main(void)
{
	int result = is_anagram("hello", "olleh");
	if (result == 1)
		printf("It's an anagram\n");
	else
		printf("It's not an anagram\n");
	printf("%d\n", result);
		
}