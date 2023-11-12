/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/21 15:48:55 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/12 18:38:16 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "minishell.h"
# include <signal.h>

void	child_signal_handler(int signal_num);
void	init_child_signal_handler(void);
void	signal_handler(int signal_num);
void	init_signal_handler(void);
void	restore_signals(void);
void	ignore_signals(void);

#endif