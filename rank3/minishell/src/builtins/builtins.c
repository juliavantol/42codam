/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:18:10 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/14 14:50:35 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	check_command(t_data *data, char *input)
{
	if (ft_strcmp(input, "pwd"))
		pwd();
	else if (ft_strcmp(input, "exit"))
		exit_shell();
	else if (ft_strcmp(input, "env"))
		env(data);
	else if (ft_strcmp(input, "export"))
		export(data, "naam", "waarde");
}

void	pwd(void)
{
	char	*path;

	path = malloc(PATH_MAX + 1);
	getcwd(path, PATH_MAX + 1);
	printf("%s\n", path);
	free(path);
}

void	env(t_data *data)
{
	int	index;

	index = 0;
	if (!data->envp)
		return ;
	while (data->envp[index] && data->envp[index])
		printf("%s\n", data->envp[index++]);
}

void	exit_shell(void)
{
	exit(1);
}
