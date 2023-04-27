/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:34:16 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/27 19:59:30 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (str != NULL)
		ft_putstr_fd(str, 2);
	exit (1);
}

int	if_empty_line(char *str)
{
	int		index;
	size_t	empty;

	index = 0;
	empty = 0;
	if (str[0] == '\n' && ft_strlen(str) == 1)
		return (1);
	while (str[index])
	{
		if (str[index] == ' ')
			empty++;
		index++;
	}
	if (empty == ft_strlen(str))
		return (1);
	return (0);
}
