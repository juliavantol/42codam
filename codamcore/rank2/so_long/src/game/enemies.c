/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemies.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 12:24:06 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/24 00:14:00 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_enemies(t_game *game)
{
	t_mouse			*mouse;

	mouse = game->mice;
	while (mouse != NULL)
	{
		printf("%d\n", mouse -> test);
		mouse = mouse -> next;
	}
}


void	add_enemy(t_game *game, mlx_image_t *img)
{
	t_mouse	*last;
	t_mouse	*new;

	last = game->mice;
	new = malloc(sizeof(t_mouse));
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
		game->map.map[mouse->img->instances[0].y / PIXELS][mouse->img->instances[0].x / PIXELS] = '0';
		mlx_delete_image(game->mlx, mouse -> img);
		put_image(game->mlx, temp, j * PIXELS, i * PIXELS);
		mouse -> img = temp;
		game->map.map[j][i] = 'X';
	}
	
}

void	try_move(t_mouse *mouse, t_game *game, int i, int j)
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
			i = (mouse->img->instances[0].x + (x * PIXELS)) / PIXELS;
			j = (mouse->img->instances[0].y + (y * PIXELS)) / PIXELS;
			if (game->map.map[j][i] == '0' || game->map.map[j][i] == 'P')
			{
				move_enemy(mouse, game, x, y);
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
	if (runs++ < ENEMY_SPEED)
		return ;
	while (mouse != NULL)
	{
		try_move(mouse, game, 0, 0);
		mouse = mouse -> next;
	}
	runs = 0;
}

void	add_enemies(t_game *game)
{
	mlx_image_t		*mouse;
	int				x;
	int				y;

	game->mice = NULL;
	x = 0;
	while (x < game->map.height)
	{
		y = 0;
		while (y < game->map.width)
		{
			if (game->map.map[x][y] == 'X')
			{
				mouse = get_picture(game->mlx, "textures/mouse/right2.png");
				add_enemy(game, mouse);
				put_image(game->mlx, mouse, x * PIXELS, y * PIXELS);
			}
			y++;
		}
		x++;
	}
}