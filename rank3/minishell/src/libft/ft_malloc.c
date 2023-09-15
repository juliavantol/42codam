/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/15 12:52:46 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/15 13:02:28 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_malloc(size_t size)
{
	void	*output;

	output = malloc(size);
	if (!output)
		ft_error("Malloc failed\n", errno);
	return (output);
}
