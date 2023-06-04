/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:59:39 by Julia         #+#    #+#                 */
/*   Updated: 2023/06/04 19:38:52 by Julia         ########   odam.nl         */
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

void	ft_error(char *msg)
{
	put_str(msg, 2);
	exit(EXIT_FAILURE);
}
