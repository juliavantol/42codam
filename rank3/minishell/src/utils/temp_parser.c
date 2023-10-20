/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   temp_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 12:36:35 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/20 14:08:58 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "builtins.h"

void	divide_command_in_redirections(t_cmd *node, char *command, int i)
{
	char		**cmd;

	cmd = ft_split(command, ' ');
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], ">") && cmd[i + 1])
		{
			node->output_redirection = true;
			add_node(&node->outputs, cmd[i + 1], TRUNCATE);
			i++;
		}
		else if (ft_strcmp(cmd[i], ">>") && cmd[i + 1])
		{
			node->output_redirection = true;
			add_node(&node->outputs, cmd[i + 1], APPEND);
			i++;
		}
		else if (ft_strcmp(cmd[i], "<") && cmd[i + 1])
		{
			node->input_redirection = true;
			add_node(&node->inputs, cmd[i + 1], READ);
			i++;
		}
		else if (ft_strcmp(cmd[i], "<<") && cmd[i + 1])
		{
			node->input_redirection = true;
			add_node(&node->inputs, cmd[i + 1], HEREDOC);
			i++;
		}
		else
			node->command_name = join_three_strs(node->command_name,
					" ", cmd[i]);
		i++;
	}
	empty_array(cmd);
}

void	make_command_structs(t_exe *executor, char **command_line_split)
{
	t_cmd	*node;
	int		i;

	i = 0;
	while (command_line_split[i])
	{
		node = ft_malloc(sizeof(t_cmd));
		node->command_name = "";
		node->outputs = NULL;
		node->inputs = NULL;
		node->output_redirection = false;
		node->input_redirection = false;
		divide_command_in_redirections(node, command_line_split[i], 0);
		executor->commands[i] = node;
		i++;
	}
	executor->commands[i] = NULL;
}

void	temp_parser(t_exe *executor, char *input)
{
	char	**command_line_split;
	int		i;

	i = 0;
	command_line_split = ft_split(input, '|');
	while (command_line_split[i] != NULL)
		i++;
	executor->command_count = i;
	executor->current_directory = get_pwd();
	executor->commands = ft_malloc(sizeof(t_cmd *) * (i + 1));
	executor->old_fds[0] = dup(READ);
	executor->exit_code = 0;
	executor->old_fds[1] = dup(WRITE);
	make_command_structs(executor, command_line_split);
	empty_array(command_line_split);
	start_executor(executor, 0);
}
