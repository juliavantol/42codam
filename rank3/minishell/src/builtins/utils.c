/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/15 02:06:06 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/19 14:18:59 by juvan-to      ########   odam.nl         */
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

char	**convert_envp(t_exe *executor)
{
	char	**envp;
	char	*temp;
	t_envp	*head;
	int		i;

	head = executor->envp_list;
	envp = ft_malloc(2000);
	if (head != NULL)
	{
		i = 0;
		while (head != NULL)
		{
			temp = join_three_strs(head->key, "=", head->value);
			envp[i++] = temp;
			free(temp);
			head = head->next;
		}
		envp[i] = NULL;
	}
	return (envp);
}
