/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 14:20:49 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/16 13:25:25 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Will move the player on the board. 1 for up, 2 for down
3 for left, 4 for right */
// void	move_player2(t_game *game, char	*path, int x, int y)
// {
// 	mlx_image_t	*temp;

// 	temp = get_picture(game->mlx, path);
// 	mlx_delete_image(game->mlx, game->player_img);
// 	put_image(game->mlx, temp, x, y);
// 	game->player_img = temp;
// 	game->player_img->instances[0].x = x;
// 	game->player_img->instances[0].y = y;
// }

/* Will move the player on the board. 1 for up, 2 for down
3 for left, 4 for right */
void	move_player(t_game *game, int direction)
{
	int			x;
	int			y;
	mlx_image_t	*temp;

	x = game->player_img->instances[0].x;
	y = game->player_img->instances[0].y;
	if (direction == 1)
	{
		temp = get_picture(game->mlx, "textures/ghosts/back.png");
		mlx_delete_image(game->mlx, game->player_img);
		put_image(game->mlx, temp, x, y);
		game->player_img = temp;
		game->player_img->instances[0].x = x;
		game->player_img->instances[0].y = y - PIXELS;
	}
	else if (direction == 2)
	{
		temp = get_picture(game->mlx, "textures/ghosts/front.png");
		mlx_delete_image(game->mlx, game->player_img);
		put_image(game->mlx, temp, x, y);
		game->player_img = temp;
		game->player_img->instances[0].x = x;
		game->player_img->instances[0].y = y + PIXELS;
	}
	else if (direction == 3)
	{
		temp = get_picture(game->mlx, "textures/ghosts/left.png");
		mlx_delete_image(game->mlx, game->player_img);
		put_image(game->mlx, temp, x, y);
		game->player_img = temp;
		game->player_img->instances[0].x = x - PIXELS;
		game->player_img->instances[0].y = y;
	}
	else if (direction == 4)
	{
		temp = get_picture(game->mlx, "textures/ghosts/right.png");
		mlx_delete_image(game->mlx, game->player_img);
		put_image(game->mlx, temp, x, y);
		game->player_img = temp;
		game->player_img->instances[0].x = x + PIXELS;
		game->player_img->instances[0].y = y;
	}
}

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
	if (game->map.map[y][x] == 'E' && check_status(game) == 1)
		close_window();
	else if (game->map.map[y][x] == 'E' || game->map.map[y][x] == '1')
		return (0);
	return (1);
}
