/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 17:37:29 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/17 16:37:13 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	env(t_exe *executor)
{
	int	index;

	index = 0;
	if (!executor->minishell_envp)
		return ;
	while (executor->minishell_envp[index] && executor->minishell_envp[index])
		printf("%s\n", executor->minishell_envp[index++]);
}

void	unset(t_exe *executor, char *name)
{
	int		index;
	int		len;
	char	**envp;

	index = find_envp_entry(executor, name);
	if (index == -1)
		return ;
	len = -1;
	while (executor->minishell_envp[len])
		len++;
	if (executor->minishell_envp)
	{
		envp = new_envp(executor->minishell_envp, len + 1, index);
		envp[len] = NULL;
		empty_envp(executor);
		executor->minishell_envp = envp;
	}
}

void	export(t_exe *executor, char *name, char *value)
{
	int		index;
	char	**envp;
	char	*line;

	index = find_envp_entry(executor, name);
	if (index != -1)
		unset(executor, name);
	index = 0;
	line = join_three_strs(name, "=", value);
	while (executor->minishell_envp[index])
		index++;
	if (executor->minishell_envp)
	{
		envp = new_envp(executor->minishell_envp, index + 1, -1);
		envp[index++] = ft_strdup(line);
		envp[index] = NULL;
		empty_envp(executor);
		executor->minishell_envp = envp;
	}
}

