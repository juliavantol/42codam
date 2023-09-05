/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/05 23:08:03 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/05 23:35:24 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(char *delimiter)
{
	char	*input;

	delimiter--;
	input = get_next_line(0);
	printf("%s\n", input);
}