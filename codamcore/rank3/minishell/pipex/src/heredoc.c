/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/05 23:08:03 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/06 22:24:31 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(char *delimiter)
{
	char	*input;

	while (1)
	{
		input = get_next_line(0);
		if (ft_strnstr(input, delimiter, 4) && ft_strlen(input) == 5
			&& input[4] == '\n')
		{
			return ;
		}
	}
}
