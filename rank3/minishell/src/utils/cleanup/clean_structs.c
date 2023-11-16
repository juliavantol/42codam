/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean_structs.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 12:44:31 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/16 13:12:03 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	free_redirection(t_filenames *node)
{
	if (node != NULL)
	{
		if (node->filename != NULL)
			free(node->filename);
		if (node->delimiter != NULL)
			free(node->delimiter);
		free(node);
	}
}

int	ctrl_d(t_exe *executor)
{
	free(executor->input);
	exit(EXIT_SUCCESS);
}
