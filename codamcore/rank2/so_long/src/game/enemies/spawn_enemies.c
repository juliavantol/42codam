/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spawn_enemies.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 15:13:19 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/28 22:19:43 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_enemy(t_game *game, int place)
{
	int 		index;
	mlx_image_t	*mouse;
	t_tile		*tile;

	index = 0;
	tile = game->map.free_tiles2;
	while (tile != NULL)
	{
		if (index == place && tile->enemy == false)
		{
			mouse = get_picture(game->mlx, "textures/mouse/right2.png");
			add_enemy(game, mouse);
			put_image(game->mlx, mouse, tile->y * PIXELS, tile->x * PIXELS);
			tile->enemy = true;
			return (1);
		}
		index++;
		tile = tile->next;
	}
	return (0);
}

void	spawn_enemies(t_game *game)
{
	int	enemy_count;
	int	index;
	int	try;

	enemy_count = game->map.free_tiles / 20;
	if (enemy_count == 0 && game->map.height > 3)
		enemy_count = 1;
	index = 0;
	while (index < enemy_count)
	{
		try = 0;
		while (try != 1)
			try = get_enemy(game, rand() % game->map.free_tiles);
		index++;
	}
}

void	add_enemy(t_game *game, mlx_image_t *img)
{
	t_mouse	*last;
	t_mouse	*new;

	last = game->mice;
	new = malloc(sizeof(t_mouse));
	if (!new)
		ft_error("Malloc\n");
	new -> img = img;
	new -> next = NULL;
	if (game->mice == NULL)
	{
		new -> next = NULL;
		game->mice = new;
	}
	else
	{
		while (last -> next != NULL)
			last = last -> next;
		last -> next = new;
	}
}
