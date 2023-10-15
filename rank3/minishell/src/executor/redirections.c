/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirections.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 16:52:52 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/15 16:06:59 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

bool	check_output_redirections(t_cmd *command)
{
	if (command->output_redirection == true)
		return (true);
	else
		return (false);
}

bool	check_input_redirections(t_cmd *command)
{
	if (command->input_redirection == true)
		return (true);
	else
		return (false);
}

void	redirect_output(t_cmd *command)
{
	int			temp_fd;
	t_filenames	*head;

	if (check_output_redirections(command) == true)
	{
		head = command->outputs;
		while (head != NULL)
		{
			temp_fd = open(head->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			dup2(temp_fd, WRITE);
			close(temp_fd);
			head = head->next;
		}
	}
}

void	redirect_input(t_cmd *command)
{
	int			temp_fd;
	t_filenames	*head;

	if (check_input_redirections(command) == true)
	{
		head = command->inputs;
		while (head != NULL)
		{
			temp_fd = open(head->filename, O_RDONLY);
			dup2(temp_fd, READ);
			head = head->next;
			if (head != NULL)
				close(temp_fd);
		}
	}
}