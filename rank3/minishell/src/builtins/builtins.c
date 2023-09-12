/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:18:10 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/12 13:28:38 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	check_command(t_data *data, char *input)
{
	if (ft_strcmp(input, "pwd"))
		print_directory();
	else if (ft_strcmp(input, "exit"))
		exit_shell();
	else if (ft_strcmp(input, "env"))
		print_env(data);
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

void	print_env(t_data *data)
{
	int	index;

	index = 0;
	while (data->envp[index])
		printf("%s\n", data->envp[index++]);
}
