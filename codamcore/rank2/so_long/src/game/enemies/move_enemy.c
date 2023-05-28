/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_enemy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 12:22:19 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/28 22:27:25 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_mouse *mouse, t_game *game, int steps_x, int steps_y)
{
	mlx_image_t	*temp;
	int			mouse_row;
	int			mouse_line;

	temp = NULL;
	if (steps_x == 0 && steps_y == -1)
		temp = get_picture(game->mlx, "textures/mouse/up2.png");
	else if (steps_x == 1 && steps_y == 0)
		temp = get_picture(game->mlx, "textures/mouse/right2.png");
	else if (steps_x == -1 && steps_y == 0)
		temp = get_picture(game->mlx, "textures/mouse/left2.png");
	else if (steps_x == 0 && steps_y == 1)
		temp = get_picture(game->mlx, "textures/mouse/down2.png");
	mouse_row = (mouse->img->instances[0].x + (steps_x * PIXELS)) / PIXELS;
	mouse_line = (mouse->img->instances[0].y + (steps_y * PIXELS)) / PIXELS;
	if (game->map.map[mouse_line][mouse_row] == '0' || game->map.map[mouse_line][mouse_row] == 'P')
	{
		game->map.map[mouse->img->instances[0].y
			/ PIXELS][mouse->img->instances[0].x / PIXELS] = '0';
		mlx_delete_image(game->mlx, mouse -> img);
		put_image(game->mlx, temp, mouse_line * PIXELS, mouse_row * PIXELS);
		mouse -> img = temp;
		game->map.map[mouse_line][mouse_row] = 'X';
	}
}

void	try_move(t_mouse *mouse, t_game *game, int height, int width)
{
	int	try;

	try = 0;
	while (try < 5)
	{
		mouse->x = (rand() % 3) - 1;
		mouse->y = (rand() % 3) - 1;
		if ((mouse->x - mouse->y) == 1 || (mouse->x - mouse->y) == -1)
		{
			height = (mouse->img->instances[0].y + (mouse->y * PIXELS)) / PIXELS;
			width = (mouse->img->instances[0].x + (mouse->x * PIXELS)) / PIXELS;
			if (game->map.map[height][width] == '0' || game->map.map[height][width] == 'P')
			{
				move_enemy(mouse, game, mouse->x, mouse->y);
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
