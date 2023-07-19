/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/19 15:11:37 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/07/19 15:23:45 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *sub(char *str, int start, int end)
{
	char *word = malloc(10000);
	int	i = 0;

	while(str[start] && start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char **output = malloc(10000);
	int count = 0;
	int i = 0;
	int start_word = 0;

	while (str[i])
	{
		start_word = i;
		while (str[i] != ' ' && str[i])
			i++;
		output[count++] = sub(str, start_word, i);
		while (str[i] && str[i] == ' ')
			i++;	
	}
	output[count] = NULL;
	return (output);
}

int main(int argc, char **argv)
{
	char **output;

	if (argc < 2)
		return (1);
	output = ft_split(argv[1]);
	while (*output)
	{
		printf("%s\n", *output);
		output++;
	}
}
