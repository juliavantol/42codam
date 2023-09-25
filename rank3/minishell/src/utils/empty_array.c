/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   empty_array.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/25 16:56:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/25 17:32:06 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	empty_executor(t_exe *executor)
{
	int	i;

	i = 0;
	while (executor->paths[i])
		free(executor->paths[i++]);
	free(executor->paths);
	executor->paths = NULL;
	i = 0;
	while (executor->minishell_envp[i])
		free(executor->minishell_envp[i++]);
	free(executor->minishell_envp);
	executor->minishell_envp = NULL;
}

void	empty_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	arr = NULL;
}
