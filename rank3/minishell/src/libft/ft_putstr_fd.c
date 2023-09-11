/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 15:02:20 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/11 15:01:55 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Outputs the string ’s’ to the given file descriptor */

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	if (s && fd)
	{
		while (index < ft_strlen(s))
		{
			write(fd, &s[index], 1);
			index++;
		}
	}
}
