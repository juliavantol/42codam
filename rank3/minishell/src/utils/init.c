/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/12 13:16:39 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/12 19:43:28 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

void	init_executor(t_exe *executor, char **envp)
{
	t_builtins	*builtins;
	int			size;

	size = 0;
	while (envp[size])
		size++;
	executor->exit_code = 0;
	executor->current_directory = get_current_directory();
	builtins = ft_malloc(7 * sizeof(t_builtins));
	builtins[0] = (t_builtins){"env", &print_env};
	builtins[1] = (t_builtins){"echo", &echo};
	builtins[2] = (t_builtins){"cd", &cd};
	builtins[3] = (t_builtins){"pwd", &print_current_directory};
	builtins[4] = (t_builtins){"export", &prepare_export};
	builtins[5] = (t_builtins){"unset", &prepare_unset};
	builtins[6] = (t_builtins){NULL, NULL};
	executor->builtins = builtins;
	init_envp(executor, envp);
}
