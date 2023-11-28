/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/28 13:38:26 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/28 14:28:54 by juvan-to      ########   odam.nl         */
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

void	prepare_export(t_exe *executor, t_cmd *command)
{
	char	*command_name;
	char	*key;
	char	*value;
	int		i;
	int		j;

	i = 0;
	command_name = extract_command(command->command_name);
	while (command_name[i] != '\0')
	{
		j = i;
		while (command_name[j] != '=' && command_name[j] != '\0')
			j++;
		key = ft_substr(command_name, i, j - i);
		i = j + 1;
		j = i;
		while (command_name[j] != ' ' && command_name[j] != '\0')
			j++;
		value = ft_substr(command_name, i, j - i); // +1 and -2 to remove quotes
		i = j + 1;
		printf("key: %s\nvalue: %s\n", key, value);
		free(key);
		free(value);
	}
	(void)executor;
	return ;
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
