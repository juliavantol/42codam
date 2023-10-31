/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/12 13:16:39 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/31 13:11:42 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

void	init_executor(t_exe *executor, char **envp)
{
	t_builtins	builtins[6];
	int			size;

	size = 0;
	while (envp[size])
		size++;
	executor->exit_code = 0;
	executor->old_fds[READ] = dup(READ);
	executor->old_fds[WRITE] = dup(WRITE);
	executor->current_directory = get_current_directory();
	builtins[0] = (t_builtins){"env", &print_env};
	builtins[1] = (t_builtins){"echo", &echo};
	builtins[2] = (t_builtins){"cd", &cd};
	// builtins[3] = (t_builtins){"unset", &unset};
	executor->builtins = builtins;
	init_envp(executor, envp);
}
