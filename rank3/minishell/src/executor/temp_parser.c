/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   temp_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 12:36:35 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/15 15:54:05 by Julia         ########   odam.nl         */
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

t_filenames	*last_node(t_filenames *filename)
{
	t_filenames	*temp;

	temp = filename;
	if (filename != NULL)
	{
		while (temp -> next != NULL)
			temp = temp -> next;
	}
	return (temp);
}

void	add_node(t_filenames **filenames, t_filenames *new)
{
	t_filenames	*last;

	if (*filenames != NULL && new != NULL)
	{
		last = last_node(*filenames);
		last -> next = new;
	}
	else
		*filenames = new;
}

t_filenames	*new_node(char *name)
{
	t_filenames	*node;

	node = malloc(sizeof(t_filenames));
	if (node == NULL)
		return (NULL);
	if (name == NULL)
		node->filename = NULL;
	else
		node->filename = ft_strdup(name);
	node->next = NULL;
	return (node);
}

void	divide_command_in_redirections(t_cmd *cmd_node, char *command, int index)
{
	t_filenames	*node;
	char		**split_on_spaces;

	split_on_spaces = ft_split(command, ' ');
	while (split_on_spaces[index])
	{
		if (ft_strcmp(split_on_spaces[index], ">"))
		{
			node = new_node(split_on_spaces[index + 1]);
			cmd_node->output_redirection = true;
			add_node(&cmd_node->outputs, node);
			index++;
		}
		else if (ft_strcmp(split_on_spaces[index], "<"))
		{
			node = new_node(split_on_spaces[index + 1]);
			cmd_node->input_redirection = true;
			add_node(&cmd_node->inputs, node);
			index++;
		}
		else
			cmd_node->command_name = join_three_strs(cmd_node->command_name, " ", split_on_spaces[index]);
		index++;
	}
	empty_array(split_on_spaces);
}

void	print_lists(t_filenames *head)
{
	while (head != NULL)
	{
		printf("%s\n", head->filename);
		head = head->next;
	}
}

void	fill_cmd_table(t_exe *executor)
{
	t_cmd	*cmd_node;
	int		index;

	index = 0;
	while (executor->commands[index] != NULL)
	{
		cmd_node = ft_malloc(sizeof(t_cmd));
		cmd_node->command_name = ft_calloc(0, 0);
		cmd_node->outputs = NULL;
		cmd_node->inputs = NULL;
		cmd_node->output_redirection = false;
		cmd_node->input_redirection = false;
		divide_command_in_redirections(cmd_node, executor->commands[index], 0);
		executor->all_commands[index] = cmd_node;
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
	executor->old_fds[0] = dup(READ);
	executor->old_fds[1] = dup(WRITE);
	executor->index = 0;
	fill_cmd_table(executor);
}
