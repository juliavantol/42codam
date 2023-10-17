/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signal_handler.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/21 15:48:34 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/17 15:19:14 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	signal_handler(int signal_num)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void) signal_num;
}

void	init_signal_handler(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
}
