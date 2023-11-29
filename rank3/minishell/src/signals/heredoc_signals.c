/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc_signals.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 16:38:31 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/29 16:38:59 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

static void	heredoc_signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		exit(130);
	}
}

void	init_heredoc_signal_handler(void)
{
	signal(SIGINT, heredoc_signal_handler);
}
