/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 14:20:49 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/11 13:27:52 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
