/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_enemy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 12:22:19 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/28 18:00:09 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_mouse *mouse, t_game *game, int width, int height)
{
	mlx_image_t	*temp;
	int			mouse_row;
	int			mouse_line;

	temp = NULL;
	mouse_row = (mouse->img->instances[0].x + (width * PIXELS)) / PIXELS;
	mouse_line = (mouse->img->instances[0].y + (height * PIXELS)) / PIXELS;
	if (width == 0 && height == -1)
		temp = get_picture(game->mlx, "textures/mouse/up2.png");
	else if (width == 1 && height == 0)
		temp = get_picture(game->mlx, "textures/mouse/right2.png");
	else if (width == -1 && height == 0)
		temp = get_picture(game->mlx, "textures/mouse/left2.png");
	else if (width == 0 && height == 1)
		temp = get_picture(game->mlx, "textures/mouse/down2.png");
	if (game->map.map[mouse_row][mouse_line] == '0' || game->map.map[mouse_row][mouse_line] == 'P')
	{
		game->map.map[mouse->img->instances[0].y
			/ PIXELS][mouse->img->instances[0].x / PIXELS] = '0';
		mlx_delete_image(game->mlx, mouse -> img);
		put_image(game->mlx, temp, mouse_row * PIXELS, mouse_line * PIXELS);
		mouse -> img = temp;
		game->map.map[mouse_row][mouse_line] = 'X';
	}
}

void	try_move(t_mouse *mouse, t_game *game, int height, int width)
{
	int	x;
	int	y;
	int	try;

	try = 0;
	while (try < 4)
	{
		x = (rand() % 3) - 1;
		y = (rand() % 3) - 1;
		if ((x - y) == 1 || (x - y) == -1)
		{
			height = (mouse->img->instances[0].y + (y * PIXELS)) / PIXELS;
			width = (mouse->img->instances[0].x + (x * PIXELS)) / PIXELS;
			if (game->map.map[height][width] == '0' || game->map.map[height][width] == 'P')
			{
				move_enemy(mouse, game, x, y);
				return ;
			}
			try++;
		}
		else
			try++;
	}
}

void	move_enemies(void *data)
{
	t_mouse		*mouse;
	t_game		*game;
	static int	runs;

	game = (t_game *)data;
	mouse = game->mice;
	check_collision(game);
	if (runs++ < ENEMY_SPEED)
		return ;
	animate_player(game, NULL, game->player_img->instances[0].x,
		game->player_img->instances[0].y);
	while (mouse != NULL)
	{
		try_move(mouse, game, 0, 0);
		mouse = mouse -> next;
	}
	runs = 0;
}
