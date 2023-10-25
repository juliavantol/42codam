/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/12 13:16:39 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/25 17:13:49 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

void	init_executor(t_exe *executor, char **envp)
{
	int	size;

	size = 0;
	while (envp[size])
		size++;
	executor->exit_code = 0;
	executor->old_fds[READ] = dup(READ);
	executor->old_fds[WRITE] = dup(WRITE);
	executor->current_directory = get_current_directory();
	init_envp(executor, envp);
}
