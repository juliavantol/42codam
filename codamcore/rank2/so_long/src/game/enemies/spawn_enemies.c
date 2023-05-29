/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spawn_enemies.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 15:13:19 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/29 23:58:43 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Puts an enemy on the tile if it's free */
int	get_enemy(t_game *game, int place)
{
	int 		index;
	mlx_image_t	*mouse;
	t_tile		*tile;

	index = 0;
	tile = game->map.free_tiles;
	while (tile != NULL)
	{
		if (index == place && tile->enemy == false)
		{
			mouse = get_picture(game->mlx, "textures/mouse/right2.png");
			add_enemy(game, mouse);
			put_image(game->mlx, mouse, tile->y * PIXELS, tile->x * PIXELS);
			game->map.map[tile->y][tile->x] = 'X';
			tile->enemy = true;
			return (1);
		}
		index++;
		tile = tile->next;
	}
	return (0);
}

/* Spawns enemies at random places */
void	spawn_enemies(t_game *game)
{
	int	enemy_count;
	int	index;
	int	try;

	enemy_count = game->map.tile_count / 25;
	if (enemy_count == 0 && game->map.height > 3)
		enemy_count = 1;
	index = 0;
	while (index < enemy_count)
	{
		try = 0;
		while (try != 1)
			try = get_enemy(game, rand() % game->map.tile_count);
		index++;
	}
	check_path_enemies(game);
}

/* Adds enemy to linked list of enemies */
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
