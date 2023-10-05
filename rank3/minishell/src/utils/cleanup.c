/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/25 16:56:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/05 17:55:33 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	empty_executor(t_exe *executor)
{
	int	i;

	i = 0;
	if (executor->paths)
	{
		while (executor->paths[i])
			free(executor->paths[i++]);
		free(executor->paths);
		executor->paths = NULL;
	}
	i = 0;
	if (executor->minishell_envp)
	{
		while (executor->minishell_envp[i])
			free(executor->minishell_envp[i++]);
		free(executor->minishell_envp);
		executor->minishell_envp = NULL;
	}
	i = 0;
	while (executor->all_commands[i])
	{
		free(executor->all_commands[i]->command);
		empty_int_array(executor->all_commands[i]->output_fds);	
		i++;
	}
}

void	empty_array(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
		arr = NULL;
	}
}

void	empty_int_array(int *arr)
{
	int	index;

	if (arr)
	{
		index = 0;
		while (arr[index])
		{
			if (arr[index] >= 0)
				close(arr[index]);
			index++;
		}
		free(arr);
        arr = NULL;
	}
}
