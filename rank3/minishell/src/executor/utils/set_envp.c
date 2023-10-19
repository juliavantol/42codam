/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_envp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/01 13:19:15 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/19 14:26:41 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

char	**get_paths(char **envp)
{
	char	*paths;
	char	**split_paths;

	while (*envp && !ft_strnstr(*envp, "PATH=", 5))
		envp++;
	paths = ft_substr(*envp, 5, ft_strlen(*envp) - 5);
	if (!paths)
		return (NULL);
	split_paths = ft_split_paths(paths);
	return (split_paths);
}
