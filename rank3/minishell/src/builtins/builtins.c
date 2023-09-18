/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:18:10 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/18 14:14:33 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	run_cmd(char *cmd, t_executor *executor)
{
	char	*path;
	char	**cmd_split;

	cmd_split = ft_split_args(cmd);
	if (cmd_split)
	{
		path = get_cmd_path(executor->paths, cmd);
		if (!path)
			error_exit("Command not found");
		if (execve(path, cmd_split, executor->minishell_envp) == -1)
		{
			ft_putstr_fd("Execve error", 2);
			error_exit("Execve error");
		}
	}
}

void	check_command(t_executor *executor, char *input)
{
	char	**split_input;

	split_input = ft_split(input, ' ');
	if (ft_strcmp(split_input[0], "pwd"))
		pwd();
	else if (ft_strcmp(split_input[0], "exit"))
		exit_shell();
	else if (ft_strcmp(split_input[0], "env"))
		env(executor);
	else if (ft_strcmp(split_input[0], "export"))
		export(executor, split_input[1], split_input[2]);
	else if (ft_strcmp(split_input[0], "unset"))
		unset(executor, split_input[1]);
	else if (ft_strcmp(split_input[0], "cd"))
		cd(split_input[1]);
	else if (ft_strcmp(split_input[0], "echo"))
		echo(split_input[1]);
	else
		run_cmd(split_input[0], executor);
}

void	pwd(void)
{
	char	*path;

	path = ft_malloc(PATH_MAX + 1);
	getcwd(path, PATH_MAX + 1);
	printf("%s\n", path);
	free(path);
}

void	cd(char *path)
{
	chdir(path);
}

void	exit_shell(void)
{
	exit(1);
}

void	echo(char *str)
{
	printf("%s\n", str);
}
