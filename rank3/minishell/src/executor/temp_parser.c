/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   temp_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 12:36:35 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/17 13:21:29 by juvan-to      ########   odam.nl         */
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

void	divide_command_in_redirections(t_cmd *node, char *command, int i)
{
	char		**cmd;

	cmd = ft_split(command, ' ');
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], ">"))
		{
			node->output_redirection = true;
			add_node(&node->outputs, cmd[i + 1], TRUNCATE, i);
			i++;
		}
		else if (ft_strcmp(cmd[i], ">>"))
		{
			node->output_redirection = true;
			add_node(&node->outputs, cmd[i + 1], APPEND, i);
			i++;
		}
		else if (ft_strcmp(cmd[i], "<"))
		{
			node->input_redirection = true;
			add_node(&node->inputs, cmd[i + 1], READ, i);
			i++;
		}
		else if (ft_strcmp(cmd[i], "<<"))
		{
			node->input_redirection = true;
			add_node(&node->inputs, cmd[i + 1], HEREDOC, i);
			i++;
		}
		else
			node->command_name = join_three_strs(node->command_name,
					" ", cmd[i]);
		i++;
	}
	empty_array(cmd);
}

void	fill_cmd_table(t_exe *executor)
{
	t_cmd	*node;
	int		i;

	i = 0;
	while (executor->commands[i] != NULL)
	{
		node = ft_malloc(sizeof(t_cmd));
		node->command_name = "";
		node->outputs = NULL;
		node->inputs = NULL;
		node->output_redirection = false;
		node->input_redirection = false;
		divide_command_in_redirections(node, executor->commands[i], 0);
		executor->all_commands[i] = node;
		i++;
	}
	executor->all_commands[i] = NULL;
}

void	temp_parser(t_exe *executor, char *input)
{
	char	**commands;
	int		i;

	i = 0;
	commands = ft_split(input, '|');
	while (commands[i] != NULL)
		i++;
	executor->command_count = i;
	executor->all_commands = ft_malloc(sizeof(t_cmd *) * (i + 1));
	executor->commands = commands;
	executor->old_fds[0] = dup(READ);
	executor->old_fds[1] = dup(WRITE);
	executor->index = 0;
	fill_cmd_table(executor);
}
