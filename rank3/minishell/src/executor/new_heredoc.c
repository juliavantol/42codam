// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   new_heredoc.c                                      :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: Julia <Julia@student.codam.nl>               +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2023/11/05 18:08:12 by Julia         #+#    #+#                 */
// /*   Updated: 2023/11/05 19:18:37 by Julia         ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

// #include "executor.h"

// static void	ft_here_sig(int signal)
// {
// 	if (signal == SIGINT)
// 	{
// 		exit(1);
// 	}
// }

// static void	ft_child_sig(int signal)
// {
// 	if (signal == SIGINT)
// 	{
// 		printf("\n");
// 	}
// }

// void	here_doc(t_filenames *head, char *delimiter)
// {
// 	char	*input;

// 	ignore_signals();
// 	signal(SIGQUIT, &ft_child_sig);
// 	signal(SIGINT, &ft_child_sig);
// 	while (1)
// 	{
// 		signal(SIGQUIT, SIG_IGN);
// 		signal(SIGINT, &ft_here_sig);
// 		input = readline("> ");
// 		if (ft_strcmp(input, delimiter))
// 			break ;
// 		free(input);
// 	}
// 	head--;
// 	restore_signals();
// }
