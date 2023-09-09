/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/05 23:08:03 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/09 22:58:57 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	here_doc(char *delimiter)
{
	int		heredoc_file;
	int		file;
	char	*input;
	size_t	len;

	len = ft_strlen(delimiter);
	input = NULL;
	heredoc_file = open(".here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		input = get_next_line(0);
		if (ft_strnstr(input, delimiter, len) && input[len] == '\n')
			break ;
		write(heredoc_file, input, ft_strlen(input));
		free(input);
	}
	close(heredoc_file);
	file = open(".here_doc", O_RDONLY);
	dup2(file, 0);
	unlink(".here_doc");
}
