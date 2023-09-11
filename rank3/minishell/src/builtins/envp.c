/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   envp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 17:37:29 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/11 17:56:48 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	create_envp(char **envp)
{
	char	**temp;
	t_env	**envp_table;

	while (*envp)
	{
		temp = ft_split(*envp, '=');
		printf("%s -->  %s\n\n", temp[0], temp[1]);
		free(temp);
		temp = NULL;
		envp++;
	}
}