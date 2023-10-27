/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/15 02:06:06 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/27 15:07:14 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

bool	detact_newline_flag(char *str)
{
	int	i;

	i = 0;
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

int	envp_size(t_exe *executor)
{
	t_envp	*head;
	int		len;

	head = executor->envp_list;
	len = 0;
	while (head != NULL)
	{
		len++;
		head = head->next;
	}
	return (len);
}

char	**convert_envp_to_char(t_exe *executor)
{
	char	**envp;
	char	*temp;
	t_envp	*head;
	int		i;

	head = executor->envp_list;
	envp = ft_malloc((envp_size(executor) + 1) * sizeof(char *));
	i = 0;
	while (head != NULL)
	{
		temp = join_three_strs(head->key, "=", head->value);
		envp[i++] = ft_strdup(temp);
		free(temp);
		head = head->next;
	}
	envp[i] = NULL;
	return (envp);
}
