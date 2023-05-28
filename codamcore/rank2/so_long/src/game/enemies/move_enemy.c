/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_enemy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 12:22:19 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/28 17:40:20 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_mouse *mouse, t_game *game, int x, int y)
{
	mlx_image_t	*temp;
	int			i;
	int			j;

	temp = NULL;
	i = (mouse->img->instances[0].x + (x * PIXELS)) / PIXELS;
	j = (mouse->img->instances[0].y + (y * PIXELS)) / PIXELS;
	if (x == 0 && y == -1)
		temp = get_picture(game->mlx, "textures/mouse/up2.png");
	else if (x == 1 && y == 0)
		temp = get_picture(game->mlx, "textures/mouse/right2.png");
	else if (x == -1 && y == 0)
		temp = get_picture(game->mlx, "textures/mouse/left2.png");
	else if (x == 0 && y == 1)
		temp = get_picture(game->mlx, "textures/mouse/down2.png");
	if (game->map.map[j][i] == '0' || game->map.map[j][i] == 'P')
	{
		game->map.map[mouse->img->instances[0].y
			/ PIXELS][mouse->img->instances[0].x / PIXELS] = '0';
		// mlx_delete_image(game->mlx, mouse -> img);
		// put_image(game->mlx, temp, j * PIXELS, i * PIXELS);
		mouse -> img = temp;
		game->map.map[j][i] = 'X';
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
			width = (mouse->img->instances[0].y + (y * PIXELS)) / PIXELS;
			height = (mouse->img->instances[0].x + (x * PIXELS)) / PIXELS;
			if (game->map.map[width][height] == '0' || game->map.map[width][height] == 'P')
			{
				printf("mouse now: %d %d\n", width, height);
				// move_enemy(mouse, game, x, y);
				try = 5;
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
