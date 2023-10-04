/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_clean.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 12:49:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/04 13:35:47 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	cmd_error(char *cmd)
{
	char	*error_msg;

	error_msg = join_three_strs("minishell: ", cmd, ": command not found\n");
	if (!error_msg)
		error_exit("Malloc error");
	ft_putstr_fd(error_msg, 2);
}

void	error_exit(char *msg)
{
	perror(msg);
	exit(errno);
}
