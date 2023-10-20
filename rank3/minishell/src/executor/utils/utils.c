/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:29:24 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/20 13:00:39 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

char	*get_cmd_path(t_exe *executor, char *cmd, int i)
{
	char	**envp;
	char	**paths;
	char	*path;

	envp = convert_envp(executor);
	paths = get_paths(envp);
	while (paths[i])
	{
		path = join_three_strs(paths[i], NULL, cmd);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	if (access(cmd, F_OK) == 0)
		return (cmd);
	cmd_error(cmd);
	exit(127);
	return (NULL);
}

int	open_file(char *filename, int mode)
{
	int	file;

	file = -1;
	if (mode == APPEND)
		file = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (mode == TRUNCATE)
		file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (mode == READ)
		file = open(filename, O_RDONLY);
	if (file < 0)
		ft_error("File couldn't be opened\n", errno);
	return (file);
}
