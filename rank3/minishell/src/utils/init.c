/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/12 13:16:39 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/25 14:41:03 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_executor(t_exe *executor, char **envp)
{
	int	size;

	size = 0;
	while (envp[size])
		size++;
	executor->minishell_envp = new_envp(envp, size, -1);
	executor->paths = get_paths(envp);
}
