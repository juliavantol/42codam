/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 17:37:29 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/15 16:48:45 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	env(t_data *data)
{
	int	index;

	index = 0;
	if (!data->envp)
		return ;
	while (data->envp[index] && data->envp[index])
		printf("%s\n", data->envp[index++]);
}

void	export(t_data *data, char *name, char *value)
{
	int		index;
	char	**envp;
	char	*line;

	index = find_envp_entry(data, name);
	if (index != -1)
		unset(data, name);
	index = 0;
	line = join_three_strs(name, "=", value);
	while (data->envp[index])
		index++;
	if (data->envp)
	{
		envp = new_envp(data->envp, index + 1, -1);
		envp[index++] = ft_strdup(line);
		envp[index] = NULL;
		empty_envp(data);
		data->envp = envp;
	}
}

void	unset(t_data *data, char *name)
{
	int		index;
	int		len;
	char	**envp;

	index = find_envp_entry(data, name);
	if (index == -1)
		return ;
	len = -1;
	while (data->envp[len])
		len++;
	if (data->envp)
	{
		envp = new_envp(data->envp, len + 1, index);
		envp[len] = NULL;
		empty_envp(data);
		data->envp = envp;
	}
}
