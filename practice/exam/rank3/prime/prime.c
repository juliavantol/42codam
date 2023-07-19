/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prime.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/19 15:54:55 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/07/19 16:35:43 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}

int is_prime(int num)
{
	int i = 2;
	if (i <= 1)
		return (0);
	
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

char *ft_join(char *s1, char *s2)
{
	char *str = malloc(10000);
	int i = 0;
	int j = 0;

	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}


char *factor(int num)
{
	char *output = malloc(2);
	char		*c = malloc(2);
	int i = 2;

	output[0] = '\0';
	while (i <= num)
	{
		while (num % i == 0)
		{
			c[0] = (i % 10) + '0';
			c[1] = '\0';
			output = ft_join(output, c);
			output = ft_join(output, " * ");
			num /= i;
		}
		i++;
	}
	return (output);
}

int	main(int argc, char **argv) 
{
    int num;
	int len;
	char *output;

    if (argc != 2)
		return (0);
	num = atoi(argv[1]);
	if (is_prime(num) == 1)
		return (0);
	else
		output = factor(num);
	len = ft_strlen(output);
	output[len - 3] = '\0';
	output = ft_join(output, " = ");
	output = ft_join(output, argv[1]);
	printf("%s\n", output);
    return 0;
}