/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirections.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 16:52:52 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/17 15:01:33 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	fill_heredoc_file(char *content)
{
	int		heredoc_file;

	heredoc_file = open_file(".here_doc", TRUNCATE);
	write(heredoc_file, content, ft_strlen(content));
	close(heredoc_file);
	heredoc_file = open_file(".here_doc", READ);
	dup2(heredoc_file, READ);
	close(heredoc_file);
	unlink(".here_doc");
}

void	here_doc(t_filenames *head, char *delimiter)
{
	char	*content;
	char	*input;
	size_t	len;

	len = ft_strlen(delimiter);
	input = NULL;
	content = "";
	while (1)
	{
		input = get_next_line(0);
		if (ft_strnstr(input, delimiter, len) && input[len] == '\n')
			break ;
		content = join_three_strs(content, NULL, input);
		free(input);
	}
	if (head->next == NULL)
		fill_heredoc_file(content);
	free(content);
}

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
