/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:18:10 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/09 23:25:49 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_pwd(void)
{
	char	*path;

	path = malloc(PATH_MAX + 1);
	getcwd(path, sizeof(path));
	printf("%s\n", path);
	return (path);
}
