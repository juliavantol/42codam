/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_heredoc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/05 18:08:12 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/06 00:46:06 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	ft_here_sig(int signal)
{
	if (signal == SIGINT)
	{
		exit(1);
	}
}

static void	ft_child_sig(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
	}
}

void	here_doc(t_filenames *head, char *delimiter)
{
	char	*input;

	ignore_signals();
	signal(SIGQUIT, &ft_child_sig);
	signal(SIGINT, &ft_child_sig);
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &ft_here_sig);
		input = readline("> ");
		if (ft_strcmp(input, delimiter))
			break ;
		free(input);
	}
	head--;
	restore_signals();
}

void	fill_heredoc_file(t_filenames *input_file, int index)
{
	char	*filename;
	char	*delimiter;
	char	*input;
	int		file;

	delimiter = input_file->filename;
	filename = join_three_strs(".heredoc", NULL, ft_itoa(index));
	file = open_file(filename, TRUNCATE);
	input = NULL;
	while (1)
	{
		input = readline("> ");
		if (ft_strcmp(input, delimiter))
			break ;
		input = join_three_strs(input, NULL, "\n");
		write(file, input, ft_strlen(input));
		free(input);
	}
	close(file);
	input_file->filename = ft_strdup(filename);
}

void	handle_heredocs(t_exe *executor)
{
	t_cmd		*head;
	t_filenames	*input_head;
	int			index;

	head = executor->commands_list;
	index = 0;
	while (head != NULL)
	{
		input_head = head->inputs;
		while (input_head != NULL)
		{
			if (input_head->mode == HEREDOC)
				fill_heredoc_file(input_head, index);
			input_head = input_head->next;
		}
		index++;
		head = head->next;
	}
}
