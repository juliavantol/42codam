/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirections.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 16:52:52 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/17 13:55:01 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	here_doc(t_filenames *head, char *delimiter)
{
	int		heredoc_file;
	char	*name;
	int		file;
	char	*input;
	size_t	len;

	len = ft_strlen(delimiter);
	input = NULL;
	name = join_three_strs(".here_doc", NULL, ft_itoa(head->index));
	if (head->next == NULL)
	{
		heredoc_file = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (heredoc_file < 0)
			ft_error("Error opening file\n", errno);
	}
	while (1)
	{
		input = get_next_line(0);
		if (ft_strnstr(input, delimiter, len) && input[len] == '\n')
			break ;
		if (head->next == NULL)
			write(heredoc_file, input, ft_strlen(input));
		free(input);
	}
	if (head->next == NULL)
	{
		close(heredoc_file);
		file = open(name, O_RDONLY);
		dup2(file, READ);
		close(file);
		unlink(name);
	}
	free(name);
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
