/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 14:20:49 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/29 23:57:43 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Checks if the player has bumped into an enemy */
void	check_collision(t_game	*game)
{
	int			x_player;
	int			y_player;
	t_mouse		*mouse;

	x_player = game->player_img->instances[0].x;
	y_player = game->player_img->instances[0].y;
	mouse = game->mice;
	while (mouse != NULL)
	{
		if (mouse->img->instances[0].x == x_player
			&& mouse->img->instances[0].y == y_player)
			stop_game(game);
		mouse = mouse -> next;
	}
}

/* Will move the player on the map */
void	move_player(t_game *game, char	*path, int x, int y)
{
	mlx_image_t	*temp;
	int			x_old;
	int			y_old;

	temp = get_picture(game->mlx, path);
	x_old = game->player_img->instances[0].x / PIXELS;
	y_old = game->player_img->instances[0].y / PIXELS;
	game->map.map[y_old][x_old] = '0';
	mlx_delete_image(game->mlx, game->player_img);
	put_image(game->mlx, temp, x, y);
	game->player_img = temp;
	game->player_img->instances[0].x = x;
	game->player_img->instances[0].y = y;
	game->map.map[y / PIXELS][x / PIXELS] = 'P';
	game->moves += 1;
	display_moves(game->mlx, game);
}

/* Check if it's a valid move */
int	check_move(t_game *game, int key)
{
	int		x;
	int		y;

	x = game->player_img->instances[0].x;
	y = game->player_img->instances[0].y;
	if (key == MLX_KEY_LEFT || key == MLX_KEY_A)
		x -= PIXELS;
	else if (key == MLX_KEY_RIGHT || key == MLX_KEY_D)
		x += PIXELS;
	else if (key == MLX_KEY_UP || key == MLX_KEY_W)
		y -= PIXELS;
	else if (key == MLX_KEY_DOWN || key == MLX_KEY_S)
		y += PIXELS;
	x = x / PIXELS;
	y = y / PIXELS;
	if (game->map.map[y][x] == 'C')
		found_collectible(game, x, y);
	if ((game->map.map[y][x] == 'E' && check_status(game) == 1))
		stop_game(game);
	else if (game->map.map[y][x] == 'E' || game->map.map[y][x] == '1')
		return (0);
	return (1);
}

/* Checks which direction player is going */
void	prepare_move(t_game *game, mlx_key_data_t key, int x, int y)
{
	if (key.key == MLX_KEY_LEFT || key.key == MLX_KEY_A)
	{
		game->direction = 'l';
		move_player(game, "textures/grandma/left2.png", x - PIXELS, y);
	}
	else if (key.key == MLX_KEY_RIGHT || key.key == MLX_KEY_D)
	{
		game->direction = 'r';
		move_player(game, "textures/grandma/right2.png", x + PIXELS, y);
	}
	else if (key.key == MLX_KEY_UP || key.key == MLX_KEY_W)
	{
		game->direction = 'u';
		move_player(game, "textures/grandma/up2.png", x, y - PIXELS);
	}
	else if (key.key == MLX_KEY_DOWN || key.key == MLX_KEY_S)
	{
		game->direction = 'd';
		move_player(game, "textures/grandma/down2.png", x, y + PIXELS);
	}	
}
