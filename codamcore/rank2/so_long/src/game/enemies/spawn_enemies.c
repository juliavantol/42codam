/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spawn_enemies.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 15:13:19 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/26 17:41:56 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_enemy(t_game *game, int place)
{
	int 		index;
	mlx_image_t	*mouse;
	t_tile		*tile;

	index = 0;
	tile = game->map.free_tiles2;
	while (tile != NULL)
	{
		if (index == place)
		{
			mouse = get_picture(game->mlx, "textures/mouse/right2.png");
			add_enemy(game, mouse);
			put_image(game->mlx, mouse, tile->y * PIXELS, tile->x * PIXELS);
			tile->enemy = true;
		}
		index++;
		tile = tile->next;
	}
}

void	spawn_enemies(t_game *game)
{
	int	enemy_count;
	int	place;
	int	index;

	enemy_count = game->map.free_tiles / 20;
	if (enemy_count == 0 && game->map.height > 3)
		enemy_count = 1;
	index = 0;
	while (index < enemy_count)
	{
		place = rand() % game->map.free_tiles;
		get_enemy(game, place);
		index++;
	}
}
