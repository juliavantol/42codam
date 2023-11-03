/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/03 14:21:27 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/03 17:50:24 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	signal_received;

void	heredoc_signal_handler(int signal_num)
{
	signal_received = QUIT;
	(void) signal_num;
}

void	init_heredoc_signal_handler(void)
{
	signal(SIGINT, heredoc_signal_handler);
	signal(SIGQUIT, SIG_IGN);
}

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
	signal_received = 0;
	ignore_signals();
	while (1 && signal_received != QUIT)
	{
		init_heredoc_signal_handler();
		if (signal_received == QUIT)
			break ;
		input = get_next_line(STDIN_FILENO);
		if (ft_strnstr(input, delimiter, len) && input[len] == '\n')
			break ;
		content = join_three_strs(content, NULL, input);
		free(input);
	}
	if (head->next == NULL)
		fill_heredoc_file(content);
	free(content);
	restore_signals();
}
