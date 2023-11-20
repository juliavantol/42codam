/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:18:10 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/20 15:10:39 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

bool	check_builtin(t_exe *executor, t_cmd *command)
{
	int	i;

	i = 0;
	while (executor->builtins[i].command)
	{
		if (ft_strcmp(command->split[0], executor->builtins[i].command))
		{
			executor->builtins[i].function(executor, command);
			return (true);
		}
		i++;
	}
	return (false);
}

char	*get_current_directory(void)
{
	char	*path;

	path = ft_malloc(PATH_MAX + 1);
	getcwd(path, PATH_MAX + 1);
	return (path);
}

void	print_current_directory(t_exe *executor, t_cmd *command)
{
	printf("%s\n", executor->current_directory);
	(void)command;
}
