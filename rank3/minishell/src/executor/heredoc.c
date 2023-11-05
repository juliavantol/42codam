/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/03 14:21:27 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/05 23:24:07 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	signal_received;

static void	ft_here_sig(int signal)
{
	if (signal == SIGINT)
		exit(1);
}

static void	ft_child_sig(int signal)
{
	if (signal == SIGINT)
		printf("\n");
}

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

void	fill_heredoc_file(void)
{
	int		heredoc_file;

	heredoc_file = open_file(".here_doc", READ);
	dup2(heredoc_file, READ);
	close(heredoc_file);
	unlink(".here_doc");
}

void	here_doc(t_filenames *head, char *delimiter)
{
	char	*input;
	int		heredoc_file;

	input = NULL;
	signal(SIGQUIT, &ft_child_sig);
	signal(SIGINT, &ft_child_sig);
	heredoc_file = open_file(".here_doc", TRUNCATE);
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &ft_here_sig);
		input = readline("> ");
		if (ft_strcmp(input, delimiter))
			break ;
		input = join_three_strs(input, NULL, "\n");
		write(heredoc_file, input, ft_strlen(input));
		free(input);
	}
	close(heredoc_file);
	if (head->next == NULL)
		fill_heredoc_file();
}
