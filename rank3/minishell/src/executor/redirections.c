/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirections.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 16:52:52 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/14 14:09:52 by Julia         ########   odam.nl         */
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
		cmd_node->output_files[index] = filename;
		cmd_node->output_fds[index] = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		index++;
		j++;
	}
	cmd_node->output_fds[index] = '\0';
}

bool	check_output_redirections(t_cmd *command)
{
	int	index;

	index = 0;
	while (command->output_fds[index])
		index++;
	if (index == 0)
		return (false);
	else
		return (true);
}

void	redirect_output(t_cmd *command)
{
	int	temp_fd;

	if (check_output_redirections(command) == true)
	{
		temp_fd = open(command->output_files[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(temp_fd, WRITE);
		close(temp_fd);
	}
}
