/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 13:35:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/18 15:03:53 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	// char *s = "Dit is een zin met woorden";
	// char *sub = ft_substr(s, 0, 3);
	// printf("Result: %s\n", sub);
	// char	str[] = "lorem ipsum dolor sit amet";
	// char	*strsub;
	// strsub = ft_substr(str, 0, 3);
	// printf("Result: %s\n", strsub);
	char	str[] = "lorem ipsum dolor sit amet";
	char	*strsub;
	char *bullshit;
	if (!(strsub = ft_substr(str, 400, 20)))
		printf("null\n");
	else
	{
		bullshit = (char *)&strsub[30];
		bullshit = "FULL BULLSHIT";
		if (strsub)
			printf("%s\n", strsub);
		else
			printf("null\n");
	}
	if (str == strsub)
		printf("A new string was not returned\n");
}
