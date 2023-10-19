/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/25 16:56:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/19 14:13:00 by juvan-to      ########   odam.nl         */
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
