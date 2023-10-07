/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   temp_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 12:36:35 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/07 23:05:23 by Julia         ########   odam.nl         */
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

void	fill_cmd_table(t_exe *executor)
{
	char	**split_on_redirection;
	t_cmd	*cmd_node;
	int		index;
	int		j;

	index = 0;
	while (executor->commands[index] != NULL)
	{
		cmd_node = ft_malloc(sizeof(t_cmd));
		split_on_redirection = ft_split(executor->commands[index], '>');
		cmd_node->command = ft_strdup(split_on_redirection[0]);
		j = 0;
		while (split_on_redirection[j])
			j++;
		j--;
		cmd_node->output_fds = ft_malloc(sizeof(int) * (j + 1));
		open_output_fd(cmd_node->output_fds, split_on_redirection, 1);
		executor->all_commands[index] = cmd_node;
		empty_array(split_on_redirection);
		index++;
	}
	executor->all_commands[index] = NULL;
}

void	temp_parser(t_exe *executor, char *input)
{
	char	**commands;
	int		index;

	index = 0;
	commands = ft_split(input, '|');
	while (commands[index] != NULL)
		index++;
	executor->command_count = index;
	executor->all_commands = ft_malloc(sizeof(t_cmd *) * (index + 1));
	executor->commands = commands;
	executor->index = 0;
	fill_cmd_table(executor);
}
