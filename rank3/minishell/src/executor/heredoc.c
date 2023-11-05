/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/03 14:21:27 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/05 18:30:15 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

// int	signal_received;

// static void	ft_here_sig(int signal)
// {
// 	if (signal == SIGINT)
// 		exit(1);
// }

// static void	ft_child_sig(int signal)
// {
// 	if (signal == SIGINT)
// 		printf("\n");
// }

// void	heredoc_signal_handler(int signal_num)
// {
// 	signal_received = QUIT;
// 	(void) signal_num;
// }

// void	init_heredoc_signal_handler(void)
// {
// 	signal(SIGINT, heredoc_signal_handler);
// 	signal(SIGQUIT, SIG_IGN);
// }

// void	fill_heredoc_file(char *content)
// {
// 	int		heredoc_file;

// 	heredoc_file = open_file(".here_doc", TRUNCATE);
// 	write(heredoc_file, content, ft_strlen(content));
// 	close(heredoc_file);
// 	heredoc_file = open_file(".here_doc", READ);
// 	dup2(heredoc_file, READ);
// 	close(heredoc_file);
// 	unlink(".here_doc");
// }

// void	here_doc2(t_filenames *head, char *delimiter)
// {
// 	char	*content;
// 	char	*input;
// 	int		len;

// 	len = ft_strlen(delimiter);
// 	input = NULL;
// 	content = "";
// 	signal(SIGQUIT, &ft_child_sig);
// 	signal(SIGINT, &ft_child_sig);
// 	while (1)
// 	{
// 		signal(SIGQUIT, SIG_IGN);
// 		signal(SIGINT, &ft_here_sig);
// 		input = get_next_line(STDIN_FILENO);
// 		if (ft_strnstr(input, delimiter, len) && input[len] == '\n')
// 			break ;
// 		content = join_three_strs(content, NULL, input);
// 		free(input);
// 	}
// 	if (head->next == NULL)
// 		fill_heredoc_file(content);
// 	free(content);
// }
