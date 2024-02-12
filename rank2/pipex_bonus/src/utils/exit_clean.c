/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_clean.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 12:49:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/08 12:10:49 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_error(char *cmd)
{
	char	*cmd_msg;
	char	*error_msg;

	cmd_msg = join_str("pipex: ", cmd);
	if (!cmd_msg)
		error_exit("Malloc error");
	error_msg = join_str(cmd_msg, ": command not found\n");
	if (!error_msg)
		error_exit("Malloc error");
	ft_putstr_fd(error_msg, 2);
}

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
