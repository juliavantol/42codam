/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/25 16:56:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/07 14:16:48 by juvan-to      ########   odam.nl         */
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
		if (temp->mode == HEREDOC)
			unlink(temp->filename);
		free(temp->filename);
		free(temp);
	}
}

void	free_command_list(t_exe *executor)
{
	t_cmd	*head;
	t_cmd	*temp;

	if (executor->commands_list == NULL)
		return ;
	head = executor->commands_list;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		empty_array(temp->split);
		temp->split = NULL;
		free(temp->command_name);
		temp->command_name = NULL;
		if (temp->outputs != NULL)
			free_filenames(temp->outputs);
		if (temp->inputs != NULL)
			free_filenames(temp->inputs);
		free(temp);
		temp = NULL;
	}
	executor->commands_list = NULL;
}

void	free_envp_list(t_exe *executor)
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
	free_command_list(executor);
	free_envp_list(executor);
	empty_array(executor->paths);
	free(executor->current_directory);
}
