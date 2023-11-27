/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/03 14:21:27 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/28 00:49:24 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int g_signal_received = 0;

static void	heredoc_signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		g_signal_received = 130;
		exit(130);
	}
}

void	init_heredoc_signal_handler(void)
{
	signal(SIGINT, heredoc_signal_handler);
}

void	fill_heredoc_file(char *filename, t_filenames *input_file)
{
	char	*input;
	char	*line;
	int		file;

	file = open_file(filename, TRUNCATE);
	input = NULL;
	init_heredoc_signal_handler();
	while (1)
	{
		input = readline("> ");
		if (ft_strcmp(input, input_file->delimiter) || !input)
		{
			free(input);
			break ;
		}
		line = join_three_strs(input, NULL, "\n");
		write(file, line, ft_strlen(line));
		free(line);
		free(input);
	}
	close(file);
	signal(SIGINT, SIG_DFL);
}

void	start_heredoc(t_exe *executor, t_filenames *input_file)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		fill_heredoc_file(input_file->filename, input_file);
		exit(EXIT_SUCCESS);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		executor->exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		executor->exit_code = 128 + WTERMSIG(status);
	if (executor->exit_code != 0)
		executor->here_doc_signaled = 1;
}

int	handle_heredocs(t_exe *executor)
{
	t_cmd		*head;
	t_filenames	*input_head;
	int			index;

	head = executor->commands_list;
	index = 0;
	ignore_signals();
	while (head != NULL)
	{
		input_head = head->inputs;
		while (input_head != NULL)
		{
			if (input_head->mode == HEREDOC)
				start_heredoc(executor, input_head);
			input_head = input_head->next;
		}
		index++;
		head = head->next;
	}
	restore_signals();
	return (0);
}
