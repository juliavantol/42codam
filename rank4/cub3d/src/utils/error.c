/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/30 12:48:05 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/30 13:01:23 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *message, bool error_message)
{
	printf("Error\n");
	if (error_message == true)
		perror(message);
	else
		printf("%s\n", message);
	exit(EXIT_FAILURE);
}
