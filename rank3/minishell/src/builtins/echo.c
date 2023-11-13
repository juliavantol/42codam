/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 16:17:40 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/13 16:39:54 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

bool	detact_newline_flag(char *str)
{
	int	i;

	i = 0;
	if (!str)
		printf("\n");
	if (str[i++] != '-')
		return (false);
	while (str[i])
	{
		if (str[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

void	print_variable(t_exe *executor, char *key)
{
	char	*value;

	value = NULL;
	if (key[0] == '$')
	{
		key++;
		value = get_variable(executor, key);
	}
	else if (key[0] == '~')
	{
		if (ft_strlen(key) == 1)
			value = get_variable(executor, "HOME");
		else
			printf("%s\n", key);
	}
	if (value)
		printf("%s", value);
}

void	echo(t_exe *executor, t_cmd *command)
{
	int		i;
	bool	newline;

	i = 1;
	newline = true;
	while (detact_newline_flag(command->split[i]))
		i++;
	if (i != 1)
		newline = false;
	while (command->split[i])
	{
		if (command->split[i][0] == '$' || command->split[i][0] == '~')
			print_variable(executor, command->split[i]);
		else
			printf("%s", command->split[i]);
		i++;
		if (command->split[i])
			printf(" ");
	}
	if (newline == true)
		printf("\n");
}
