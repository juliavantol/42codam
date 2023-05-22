/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemies.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 12:24:06 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/22 12:26:20 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_enemy(t_enemy **enemies, t_enemy *new)
{
	t_enemy	*last;

	last = *enemies;
	if (*enemies == NULL)
	{
		new -> next = NULL;
		*enemies = new;
	}
	else
	{
		while (last -> next != NULL)
			last = last -> next;
		new -> next = NULL;
		last -> next = new;
	}
}