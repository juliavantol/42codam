/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/28 13:38:26 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/29 01:47:47 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*extract_command(char *str)
{
	char	*output;
	int		i;

	i = 0;
	while (str[i] != ' ')
		i++;
	output = ft_substr(str, i + 1, ft_strlen(str));
	return (output);
}


char	*extract_key(char *str, int *i)
{
	char	*key;
	int		index;

	key = NULL;
	index = *i - 2;
	while (str[index] && str[index] != ' ')
	{
		printf("%c", str[index]);
		index--;
	}
	return (key);
}

void	loop_until_specific_char(char *str, char c, int *i)
{
	while (str[*i] && str[*i] != c)
	{
		printf("%c", str[*i]);
		(*i)++;
	}
	(*i)++;
}

void	extract_key_value_pairs(t_exe *executor, char *str)
{
	char	**temp_split;
	char	**split_key;
	char	*value;
	int		i;

	i = 0;
	temp_split = ft_split(str, ' ');
	value = ft_strdup("");
	while (temp_split[i])
	{
		if (ft_strnstr(temp_split[i], "=", ft_strlen(temp_split[i])))
		{
			if (ft_strlen(value) > 0)
			{
				export(executor, split_key[0], value);
				free(value);
				value = ft_strdup("");
			}
			split_key = ft_split(temp_split[i], '=');
			value = join_three_strs(value, " ", split_key[1]);
		}
		else
			value = join_three_strs(value, " ", temp_split[i]);
		i++;
	}
	if (ft_strlen(value) > 0)
	{
		export(executor, split_key[0], value);
		free(value);
	}
}

void	prepare_export(t_exe *executor, t_cmd *command)
{
	char	*command_name;

	command_name = extract_command(command->command_name);
	extract_key_value_pairs(executor, command_name);
	return ;
	(void)executor;
}

void	prepare_export_save(t_exe *executor, t_cmd *command)
{
	char	**split_temp;
	int		i;

	i = 1;
	while (command->split[i])
	{
		split_temp = ft_split(command->split[i], '=');
		export(executor, split_temp[0], split_temp[1]);
		empty_array(split_temp);
		i++;
	}
	return ;
}

void	export(t_exe *executor, char *key, char *value)
{
	t_envp	*head;

	head = executor->envp_list;
	while (head != NULL)
	{
		if (ft_strcmp(head->key, key))
		{
			free(head->value);
			head->value = ft_strdup(value);
			return ;
		}
		head = head->next;
	}
	add_node_envp(&executor->envp_list, key, value);
}
