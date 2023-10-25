/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/25 16:56:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/25 14:37:59 by juvan-to      ########   odam.nl         */
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
	free(executor->commands);
}

void	free_envp(t_exe *executor)
{
	t_envp	*head;
	t_envp	*temp;

	if (executor->envp_list == NULL)
		return ;
	head = executor->envp_list;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->key);
		free(temp->value);
		temp->key = NULL;
		temp->value = NULL;
		free(temp);
		temp = NULL;
	}
	free(head);
	executor->envp_list = NULL;
}

void	empty_executor(t_exe *executor)
{
	free(executor->input);
	free_cmds(executor);
	free_envp(executor);
	print_env(executor);
	empty_array(executor->paths);
}
