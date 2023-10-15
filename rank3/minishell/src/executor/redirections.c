/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirections.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 16:52:52 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/15 16:44:52 by Julia         ########   odam.nl         */
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
	int			fd;
	t_filenames	*head;

	if (check_output_redirections(command) == true)
	{
		head = command->outputs;
		while (head != NULL)
		{
			if (head->mode == TRUNCATE)
				fd = open(head->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			else
				fd = open(head->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
			dup2(fd, WRITE);
			close(fd);
			head = head->next;
		}
	}
}

void	redirect_input(t_cmd *command)
{
	int			fd;
	t_filenames	*head;

	if (check_input_redirections(command) == true)
	{
		head = command->inputs;
		while (head != NULL)
		{
			if (head->mode == HEREDOC)
				here_doc(head->filename);
			else
			{
				fd = open(head->filename, O_RDONLY);
				dup2(fd, READ);
				if (head->next != NULL)
					close(fd);
			}
			head = head->next;
		}
	}
}
