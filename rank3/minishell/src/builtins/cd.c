/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 13:40:15 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/13 13:58:24 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*find_cd_path(t_exe *executor, char *str)
{
	char	*path;

	path = NULL;
	if (ft_strcmp(str, "-"))
	{
		path = get_variable(executor, "OLDPWD");
		printf("%s\n", path);
	}
	if (path == NULL)
		return (str);
	return (path);
}

void	cd(t_exe *executor, t_cmd *command)
{
	int		return_value;
	char	*path;
	char	*pwd;

	path = command->split[1];
	path = find_cd_path(executor, path);
	return_value = chdir(path);
	if (return_value != 0)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		perror("");
	}
	else
	{
		export(executor, "OLDPWD", executor->current_directory);
		free(executor->current_directory);
		pwd = get_current_directory();
		executor->current_directory = pwd;
		export(executor, "PWD", pwd);
	}
}
