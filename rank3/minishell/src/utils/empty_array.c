/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   empty_array.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/25 16:56:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/25 16:58:01 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	empty_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
