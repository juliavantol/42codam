/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/19 13:47:12 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/19 14:23:06 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*get_variable(t_exe *executor, char *name)
{
	int		name_len;
	int		index;

	index = find_envp_entry(executor, name);
	if (index != -1)
	{
		name_len = 1 + ft_strlen(name);
		return (name_len + executor->minishell_envp[index]);
	}
	return (NULL);
}
