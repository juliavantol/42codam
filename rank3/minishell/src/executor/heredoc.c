/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/03 14:21:27 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/07 11:30:01 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	signal_received;

static void	heredoc_signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		signal_received = 1;
		printf("\n");
		exit(1);
	}
}

void	init_heredoc_signal_handler(void)
{
	signal(SIGINT, heredoc_signal_handler);
}

void	fill_heredoc_file(char *filename, t_filenames *input_file)
{
	char	*input;
	int		file;

	file = open_file(filename, TRUNCATE);
	input_file->filename = ft_strdup(filename);
	input = NULL;
	signal(SIGINT, heredoc_signal_handler);
	while (signal_received == 0)
	{
		input = readline("> ");
		if (ft_strcmp(input, input_file->delimiter) || !input)
			break ;
		input = join_three_strs(input, NULL, "\n");
		write(file, input, ft_strlen(input));
		free(input);
	}
	close(file);
	signal(SIGINT, SIG_DFL);
}

void	start_heredoc(t_filenames *input_file)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		fill_heredoc_file(input_file->filename, input_file);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (status != 0)
		signal_received = 1;
}

void	handle_heredocs(t_exe *executor)
{
	t_cmd		*head;
	t_filenames	*input_head;
	int			index;

	head = executor->commands_list;
	index = 0;
	ignore_signals();
	while (head != NULL && signal_received == 0)
	{
		input_head = head->inputs;
		while (input_head != NULL && signal_received == 0)
		{
			if (input_head->mode == HEREDOC)
				start_heredoc(input_head);
			input_head = input_head->next;
		}
		index++;
		head = head->next;
	}
	restore_signals();
}
