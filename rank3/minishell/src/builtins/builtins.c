/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:18:10 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/15 14:40:39 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	check_command(t_data *data, char *input)
{
	char	**split_input;

	split_input = ft_split(input, ' ');
	if (ft_strcmp(split_input[0], "pwd"))
		pwd();
	else if (ft_strcmp(split_input[0], "exit"))
		exit_shell();
	else if (ft_strcmp(split_input[0], "env"))
		env(data);
	else if (ft_strcmp(split_input[0], "export"))
		export(data, split_input[1], split_input[2]);
	else if (ft_strcmp(split_input[0], "unset"))
		unset(data, split_input[1]);
}

void	pwd(void)
{
	char	*path;

	path = ft_malloc(PATH_MAX + 1);
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
