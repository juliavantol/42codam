/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 12:49:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/31 15:16:19 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *msg)
{
	perror(msg);
	exit(errno);
}

void	free_cmd_split(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_split[i])
		free(pipex->cmd_split[i++]);
	free(pipex->cmd_split);
}
