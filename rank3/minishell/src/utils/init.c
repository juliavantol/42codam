/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/12 13:16:39 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/15 14:13:01 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_data *data, char **envp)
{
	int	size;

	size = 0;
	while (envp[size])
		size++;
	data->envp = new_envp(envp, size, -1);
	data->envp[size] = NULL;
}
