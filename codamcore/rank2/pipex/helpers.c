/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:29:24 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/22 13:59:11 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *msg)
{
	perror(msg);
	exit(errno);
}

void	parent_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->paths[i])
		free(pipex->paths[i++]);
	free(pipex->paths);
	i = 0;
	while (pipex->cmd_split[i])
		free(pipex->cmd_split[i++]);
	free(pipex->cmd_split);
	i = 0;
	while (pipex->full_envp[i])
		free(pipex->full_envp[i++]);
	free(pipex->full_envp);
}

void	check_envp(t_pipex *pipex, char **envp)
{
	char		**paths;
	const char	*temp[] = {"/usr/local/sbin/",
		"/usr/local/bin/", "/usr/sbin/", "/usr/bin/", "/sbin/", "/bin/"};
	int			index;

	pipex->full_envp = envp;
	if (envp == NULL || envp[0] == NULL)
	{
		index = 0;
		paths = malloc(7 * sizeof(char *));
		if (paths == NULL)
			error_exit("Malloc error");
		while (index < 6)
		{
			paths[index] = ft_strdup(temp[index]);
			index++;
		}
		paths[index] = NULL;
		pipex->paths = paths;
	}
	else
	{
		while (*envp && !ft_strnstr(*envp, "PATH=", ft_strlen(*envp)))
			envp++;
		pipex->paths = ft_split_env(ft_substr(*envp, 5, ft_strlen(*envp) - 5),
				':');
	}
}

char	*first_cmd(char *cmd)
{
	int		index;
	int		size;
	char	*first_cmd;

	size = 0;
	while (cmd[size] != ' ' && cmd[size])
		size++;
	first_cmd = (char *)malloc((size + 1) * sizeof(char));
	index = 0;
	while (index < size)
	{
		first_cmd[index] = cmd[index];
		index++;
	}
	first_cmd[index] = '\0';
	return (first_cmd);
}

char	*get_cmd_path(char **paths, char	*cmd)
{
	char		*path;
	char		*err;

	cmd = first_cmd(cmd);
	while (*paths)
	{
		path = ft_strjoin(*paths, cmd);
		if (!path)
			error_exit("Malloc");
		if (access(path, F_OK) == 0)
			return (free(cmd), path);
		free(path);
		paths++;
	}
	if (access(cmd, F_OK) == 0)
		return (cmd);
	err = ft_strjoin(ft_strjoin("pipex: ", cmd), ": command not found\n");
	ft_putstr_fd(err, 2);
	exit(127);
	return (NULL);
}
