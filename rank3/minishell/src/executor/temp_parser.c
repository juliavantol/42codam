/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   temp_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 12:36:35 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/04 13:38:10 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "builtins.h"

void	check_command(t_exe *executor, char *input)
{
	char	**split_input;

	split_input = ft_split(input, ' ');
	temp_parser(executor, input);
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
		echo(executor, split_input + 1);
	else
		start_executor(executor);
	empty_array(split_input);
}

void	temp_parser(t_exe *executor, char *input)
{
	char	**commands;
	t_cmd	*cmd_node;
	char	**split_on_redirection;
	int		index;
	int		j;

	index = 0;
	commands = ft_split(input, '|');
	while (commands[index] != NULL)
	{
		split_on_redirection = ft_split(commands[index], '>');
		printf("%s\n", commands[index]);
		index++;
	}
	executor->commands = commands;
	executor->command_count = index;
	return ;
	index = 0;
	while (commands[index] != NULL)
	{
		split_on_redirection = ft_split(commands[index], '>');
		j = 0;
		while (split_on_redirection[j] != NULL)
		{
			printf("%s\n", split_on_redirection[j]);
			j++;
		}
		// split_on_redirection = ft_split(input, ' ');
		index++;
	}
	exit(1);
}
