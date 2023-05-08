/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 12:46:09 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/08 16:42:34 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_background(mlx_t *mlx, t_imgs pics, char **map)
{
	int x;
	int y;
	int	height;
	int width;

	height = 0;
	x = 0;
	while (map[height])
	{
		width = 0;
		y = 0;
		while (map[height][width])
		{
			if (mlx_image_to_window(mlx, pics.floor, y, x) < 0)
       			ft_error("Image error\n");
			width++;
			y += PIXELS;
		}
		x += PIXELS;
		height++;
	}
}

void	parse_map(mlx_t *mlx, t_imgs pics, char **map, t_game *game)
{
	int x;
	int y;
	int	height;
	int width;

	height = 0;
	x = 0;
	while (map[height])
	{
		width = 0;
		y = 0;
		while (map[height][width])
		{
			if (map[height][width] == '1')
				put_image(mlx, pics.wall, x, y);
			else if (map[height][width] == 'P')
			{
				put_image(mlx, pics.player_front, x, y);
				game->player_img = pics.player_front;
				game->player_x = x;
				game->player_y = y;
			}
			else if (map[height][width] == 'C')
				put_image(mlx, pics.collectible, x, y);
			else if (map[height][width] == 'E')
				put_image(mlx, pics.exit, x, y);
			width++;
			y += PIXELS;
		}
		x += PIXELS;
		height++;
	}
}

void	key_hooks(mlx_key_data_t keydata, void *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		exit(1);
	if (check_move(game, keydata.key) == 0)
		return ;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		game->player_img->instances[0].x -= PIXELS;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)	
		game->player_img->instances[0].x += PIXELS;
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
		game->player_img->instances[0].y -= PIXELS;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		game->player_img->instances[0].y += PIXELS;
}

void	open_window(t_map map_data)
{
	mlx_t			*mlx;
	t_imgs			pics;
	t_game			game;
	int				height;
	
	height = 0;
	while (map_data.map[height])
		height++;
	mlx = mlx_init((ft_strlen(*(map_data.map)) * PIXELS), (height * PIXELS), "so_long", false);
	if (mlx == NULL)
		ft_error("MLX error\n");
	pics = set_images(mlx);
	game.map = map_data.map;
	fill_background(mlx, pics, map_data.map);
	parse_map(mlx, pics, map_data.map, &game);
	mlx_key_hook(mlx, &key_hooks, &game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
