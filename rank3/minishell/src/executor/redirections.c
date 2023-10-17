/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirections.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 16:52:52 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/17 14:10:52 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	fill_heredoc_file(char *content)
{
	int		heredoc_file;

	heredoc_file = open(".here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(heredoc_file, content, ft_strlen(content));
	close(heredoc_file);
	heredoc_file = open(".here_doc", O_RDONLY);
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
				here_doc(head, head->filename);
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
