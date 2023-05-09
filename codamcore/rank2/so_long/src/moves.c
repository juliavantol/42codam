/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 14:20:49 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/10 01:48:33 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_move(t_game *game, int key)
{
	int		x;
	int		y;

	x = game->player_img->instances[0].x;
	y = game->player_img->instances[0].y;
	if (key == MLX_KEY_LEFT)
		x -= PIXELS;
	else if (key == MLX_KEY_RIGHT)
		x += PIXELS;
	else if (key == MLX_KEY_UP)
		y -= PIXELS;
	else if (key == MLX_KEY_DOWN)
		y += PIXELS;
	x = x / PIXELS;
	y = y / PIXELS;
	if (game->map.map[y][x] == '1')
		return (0);
	if (game->map.map[y][x] == 'C')
		found_collectible(game, x, y);
	return (1);
}
