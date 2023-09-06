/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/05 23:08:03 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/06 22:27:40 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(char *delimiter)
{
	char	*input;
	size_t	delimiter_len;

	delimiter_len = ft_strlen(delimiter);
	while (1)
	{
		input = get_next_line(0);
		if (ft_strnstr(input, delimiter, delimiter_len)
			&& ft_strlen(input) == delimiter_len + 1 && input[4] == '\n')
		{
			return ;
		}
	}
}
