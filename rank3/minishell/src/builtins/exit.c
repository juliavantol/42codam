/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/30 11:34:56 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/30 11:40:32 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	exit_shell(t_exe *executor, int code, t_cmd *command)
{
	int	i;

	if (command)
	{
		redirect_input(command);
		redirect_output(command);
	}
	i = 0;
	while (command->split[i])
		i++;
	if (i > 2)
	{
		cmd_error("exit", ": too many arguments\n");
		return ;
	}
	else if (i == 2)
		code = ft_atoi(command->split[1]);
	if (code > 255)
		code = code % 256;
	empty_executor(executor);
	exit(code);
}
