/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:29:24 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/20 17:08:06 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *msg)
{
	perror(msg);
	exit(errno);
}

char	**delete_sub(const char *s)
{
	char	*new_str;
	char	**split_new_str;
	int		index;
	char	two;
	char	one;

	two = s[ft_strlen(s) - 2];
	one = s[ft_strlen(s) - 1];
	new_str = (char *)malloc(10 * sizeof(char));
	index = 0;
	while (s[index - 1] != two && s[index])
	{
		new_str[index] = s[index];
		index++;
	}
	new_str[index++] = ' ';
	new_str[index++] = two;
	new_str[index++] = one;
	new_str[index++] = '\0';
	split_new_str = ft_split(new_str, one);
	return (split_new_str);
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

char	*get_cmd_path(char **paths, char	*cmd)
{
	char		*path;
	char		*err;

	cmd = *ft_split(cmd, ' ');
	while (*paths)
	{
		path = ft_strjoin(*paths, cmd);
		if (access(path, F_OK) == 0)
			return (path);
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
