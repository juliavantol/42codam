/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/15 12:55:41 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/15 13:01:35 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(char *msg, int err_code)
{
	if (msg)
		printf("%s\n", msg);
	exit(err_code);
}
