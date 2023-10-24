/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/25 16:56:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/24 13:00:05 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

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

void	free_filenames(t_filenames *list)
{
	t_filenames	*temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp->filename);
		free(temp);
	}
}

void	free_command(t_cmd	*command)
{
	free(command->command_name);
	// free_filenames(command->inputs);
	// free_filenames(command->outputs);
}

void	free_cmds(t_exe *executor)
{
	int	i;

	i = 0;
	while (i < executor->command_count)
	{
		if (executor->commands[i]->command_name != NULL)
			free(executor->commands[i]->command_name);
		if (executor->commands[i]->outputs != NULL)
			free_filenames(executor->commands[i]->outputs);
		if (executor->commands[i]->inputs != NULL)
			free_filenames(executor->commands[i]->inputs);
		free(executor->commands[i]);
		i++;
	}
}

void	free_envp(t_envp *list)
{
	t_envp	*temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}

void	empty_executor(t_exe *executor)
{
	int	i;

	free(executor->input);
	// free_cmds(executor);
	free_envp(executor->envp_list);
	i = 0;
	if (executor->envp)
	{
		while (executor->envp[i])
			free(executor->envp[i++]);
		free(executor->envp);
		executor->envp = NULL;
	}
	i = 0;
	if (executor->paths)
	{
		while (executor->paths[i])
		{
			free(executor->paths[i]);
			i++;
		}
		free(executor->paths);
		executor->paths = NULL;
	}
}
