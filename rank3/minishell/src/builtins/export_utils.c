/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 12:41:24 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/29 13:42:19 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

// export test1="eerste zin" test2="dit is de tweede zin"

void	handle_key(t_exe *executor, char **split_key, char **value)
{
	// char	*temp;

	if (ft_strlen(*value) > 0)
	{
		export(executor, split_key[0], *value);
		free(*value);
		*value = ft_strdup("");
	}
	// temp = *value;
	// *value = join_three_strs(*value, " ", split_key[1]);
	// free(temp);
}

void	handle_value(char **split_key, char **value)
{
	char	*temp;

	temp = *value;
	*value = join_three_strs(*value, " ", split_key[1]);
	free(temp);
}

void	export_all_keys(t_exe *executor, char **cmd_split, int i)
{
	char	**split_key;
	char	*value;

	value = ft_strdup("");
	while (cmd_split[i])
	{
		if (ft_strnstr(cmd_split[i], "=", ft_strlen(cmd_split[i])))
		{
			if (split_key != NULL)
				handle_key(executor, split_key, &value);
			split_key = ft_split(cmd_split[i], '=');
			handle_value(split_key, &value);
		}
		else
			value = join_three_strs(value, " ", cmd_split[i]);
		i++;
	}
	if (split_key != NULL && ft_strlen(value) > 0)
	{
		export(executor, split_key[0], value);
		free(value);
	}
}
