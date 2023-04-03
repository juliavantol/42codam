/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 14:00:10 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/30 14:01:26 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	leaks(void)
{
	system("leaks test");
}

int	main(void)
{
	printf("hey\n");
	leaks();
}