/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:18:10 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/17 16:02:20 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

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
	int	return_value;

	return_value = chdir(path);
	if (return_value != 0)
	{
		printf("couldn't find path\n");
	}
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
