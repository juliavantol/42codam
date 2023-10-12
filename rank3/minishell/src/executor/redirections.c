/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirections.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 16:52:52 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/12 14:02:52 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	open_output_fd(t_cmd *cmd_node, char **files, int j)
{
	char	*filename;
	int		index;

	index = 0;
	while (files[j])
	{
		cmd_node->output_redirection = true;
		filename = ft_split(files[j], ' ')[0];
		cmd_node->output_fds[index] = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		free(filename);
		index++;
		j++;
	}
	cmd_node->output_fds[index] = '\0';
}

void	check_output_redirections(t_exe *executor, t_cmd *command)
{
	int	index;

	index = 0;
	executor->fd_out = STDOUT_FILENO;
	while (command->output_fds[index])
	{
		executor->fd_out = command->output_fds[index];
		return ;
		index++;
	}
}