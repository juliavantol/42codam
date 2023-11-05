/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirections.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 16:52:52 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/05 19:15:30 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	redirect_output(t_cmd *command)
{
	int			file;
	t_filenames	*head;

	if (command->output_redirection == false)
		return ;
	head = command->outputs;
	while (head != NULL)
	{
		if (head->mode == TRUNCATE)
			file = open_file(head->filename, TRUNCATE);
		else
			file = open_file(head->filename, APPEND);
		dup2(file, WRITE);
		close(file);
		head = head->next;
	}
}

void	redirect_input(t_cmd *command)
{
	int			file;
	t_filenames	*head;

	if (command->input_redirection == false)
		return ;
	head = command->inputs;
	while (head != NULL)
	{
		if (head->mode == HEREDOC)
			here_doc(head, head->filename);
		else
		{
			file = open_file(head->filename, READ);
			dup2(file, READ);
			if (head->next != NULL)
				close(file);
		}
		head = head->next;
	}
}
