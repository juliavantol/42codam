/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strcap.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 14:58:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/06/14 15:31:11 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// gcc -Wall -Wextra -Werror strcap.c -o cap && ./cap "hALLo	HALLOo TEST" "hALLo HALLOo TEST"

char lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

char upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int	main(int argc, char **argv)
{
	int index = 1;
	char	c;
	int	i = 0;

	if (argc < 2)
		write(1, "\n", 1);
	else
	{
		while(argv[index])
		{
			i = 0;
			while (argv[index][i])
			{
				c = lower(argv[index][i]);
				if (argv[index][i + 1] == ' ' || argv[index][i + 1] == '\0'
					|| argv[index][i + 1] == '\t')
					c = upper(argv[index][i]);
				write(1, &c, 1);
				i++;
			}
			index++;
			write(1, "\n", 1);
		}
	}
}
