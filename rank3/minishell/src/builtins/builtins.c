/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:18:10 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/25 17:26:11 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	check_command(t_exe *executor, char *input)
{
	char	**split_input;
	int	i;

	i = 0;
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
		echo(executor, ++split_input);
	else
		execute(executor, input);
	while (split_input[i])
		free(split_input[i++]);
	free(split_input);
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

void	echo(t_exe *executor, char **str)
{
	char	*value;
	bool	newline;
	int		i;

	i = 0;
	newline = true;
	while (detact_newline_flag(str[i]))
		i++;
	if (i != 0)
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
}
