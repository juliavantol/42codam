/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   temp_executor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 12:36:35 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/28 13:06:46 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	temp_parser(t_exe *executor, char *input)
{
	char	**commands;
	int		index;

	index = 0;
	commands = ft_split(input, '|');
	while (commands[index] != NULL)
		index++;
	executor->commands = commands;
	executor->command_count = index;
}
