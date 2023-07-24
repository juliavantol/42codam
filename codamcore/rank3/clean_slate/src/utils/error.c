/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:59:39 by Julia         #+#    #+#                 */
/*   Updated: 2023/06/12 12:48:25 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_str(char *str, int fd)
{
	int	index;

	index = 0;
	while (str[index])
		write(fd, &str[index++], 1);
}

void	put_char(char c)
{
	write(1, &c, 1);
}

void	ft_error(char *msg)
{
	put_str(msg, 2);
	exit(EXIT_FAILURE);
}
