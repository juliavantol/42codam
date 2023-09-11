/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:18:10 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/11 17:46:05 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	check_command(char *input, char **envp)
{
	create_envp(envp);
	if (ft_strcmp(input, "pwd"))
		print_directory();
	else if (ft_strcmp(input, "exit"))
		exit_shell();
	else if (ft_strcmp(input, "env"))
		print_env(envp);
}

void	print_directory(void)
{
	char	*path;

	path = malloc(PATH_MAX + 1);
	getcwd(path, PATH_MAX + 1);
	printf("%s\n", path);
	free(path);
}

void	exit_shell(void)
{
	exit(1);
}

void	print_env(char **envp)
{
	while (*envp)
	{
		printf("%s\n", *envp);
		envp++;
	}
}
