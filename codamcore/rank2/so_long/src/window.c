/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 12:46:09 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/10 01:44:17 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_background(mlx_t *mlx, t_imgs pics, t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.height)
	{
		y = 0;
		while (y < game->map.width)
		{
			if (mlx_image_to_window(mlx, pics.floor,
					y * PIXELS, x * PIXELS) < 0)
				ft_error("Image error\n");
			y++;
		}
		x++;
	}
}

void	parse_map(mlx_t *mlx, t_imgs pics, t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.height)
	{
		y = 0;
		while (y < game->map.width)
		{
			if (game->map.map[x][y] == '1')
				put_image(mlx, pics.wall, x * PIXELS, y * PIXELS);
			else if (game->map.map[x][y] == 'P')
			{
				put_image(mlx, pics.player_front, x * PIXELS, y * PIXELS);
				game->player_img = pics.player_front;
			}
			else if (game->map.map[x][y] == 'C')
				put_collectible(mlx, game, x * PIXELS, y * PIXELS);
			else if (game->map.map[x][y] == 'E')
				put_image(mlx, pics.exit, x * PIXELS, y * PIXELS);
			y++;
		}
		x++;
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

void	open_window(t_game game)
{
	mlx_t			*mlx;
	t_imgs			pics;

	mlx = mlx_init(game.map.width * PIXELS, (game.map.height * PIXELS), "so_long", false);
	if (mlx == NULL)
		ft_error("MLX error\n");
	pics = set_images(mlx);
	fill_background(mlx, pics, &game);
	parse_map(mlx, pics, &game);
	mlx_key_hook(mlx, &key_hooks, &game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
