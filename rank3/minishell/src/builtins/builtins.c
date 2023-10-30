/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:18:10 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/30 21:18:39 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

bool	check_builtin(t_exe *executor, t_cmd *command)
{
	char	**name;

	name = ft_split(command->command_name, ' ');
	if (ft_strcmp(name[0], "pwd") == true)
		printf("%s\n", executor->current_directory);
	else if (ft_strcmp(name[0], "echo") == true)
		echo(executor, command, 1);
	else if (ft_strcmp(name[0], "env") == true)
		print_env(executor);
	else if (ft_strcmp(name[0], "cd") == true)
		cd(executor, name[1]);
	else if (ft_strcmp(name[0], "export") == true)
		export(executor, name[1], name[2]);
	else if (ft_strcmp(name[0], "unset") == true)
		unset(executor, name[1]);
	else
	{
		empty_array(name);
		return (false);
	}
	empty_array(name);
	return (true);
}

char	*get_current_directory(void)
{
	char	*path;

	path = ft_malloc(PATH_MAX + 1);
	getcwd(path, PATH_MAX + 1);
	return (path);
}

void	cd(t_exe *executor, char *path)
{
	int		return_value;
	char	*pwd;

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

void	exit_shell(t_exe *executor, int code)
{
	empty_executor(executor);
	exit(code);
}

void	echo(t_exe *executor, t_cmd *command, int i)
{
	char	**str;
	char	*value;
	bool	newline;

	str = ft_split(command->command_name, ' ');
	newline = true;
	while (detact_newline_flag(str[i]))
		i++;
	if (i != 1)
		newline = false;
	while (str[i])
	{
		value = get_variable(executor, str[i]);
		if (value)
			printf("%s", value);
		else
			printf("%s", str[i]);
		i++;
		if (str[i])
			printf(" ");
	}
	if (newline == true)
		printf("\n");
	empty_array(str);
}
