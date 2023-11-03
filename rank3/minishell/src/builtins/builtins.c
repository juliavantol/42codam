/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:18:10 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/03 12:40:40 by juvan-to      ########   odam.nl         */
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
	if (ft_strcmp(command->split[0], "exit")
		&& executor->index == executor->command_count - 1)
		exit_shell(executor, EXIT_SUCCESS, command);
	return (false);
}

char	*get_current_directory(void)
{
	char	*path;

	path = ft_malloc(PATH_MAX + 1);
	getcwd(path, PATH_MAX + 1);
	return (path);
}

void	cd(t_exe *executor, t_cmd *command)
{
	int		return_value;
	char	*path;
	char	*pwd;

	path = command->split[1];
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
		free(executor->current_directory);
		pwd = get_current_directory();
		executor->current_directory = pwd;
		export(executor, "PWD", pwd);
	}
}

void	print_current_directory(t_exe *executor, t_cmd *command)
{
	printf("%s\n", executor->current_directory);
	(void)command;
}

void	echo(t_exe *executor, t_cmd *command)
{
	int		i;
	char	*value;
	bool	newline;

	i = 1;
	newline = true;
	while (detact_newline_flag(command->split[i]))
		i++;
	if (i != 1)
		newline = false;
	while (command->split[i])
	{
		value = get_variable(executor, command->split[i]);
		if (value)
			printf("%s", value);
		else
			printf("%s", command->split[i]);
		i++;
		if (command->split[i])
			printf(" ");
	}
	if (newline == true)
		printf("\n");
}
