/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 12:46:09 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/10 17:57:55 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_backdrop(mlx_t *mlx, t_imgs pics, t_game *game)
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

void	key_hooks(mlx_key_data_t key, void *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_RELEASE)
		exit(1);
	if (check_move(game, key.key) == 0)
		return ;
	else if (key.action == MLX_RELEASE)
	{
		game->moves += 1;
		ft_putstr_fd("Moves: ", 1);
		ft_putstr_fd(ft_itoa(game->moves), 1);
		ft_putstr_fd("\n", 1);
	}
	if ((key.key == MLX_KEY_LEFT || key.key == MLX_KEY_A)
		&& key.action == MLX_RELEASE)
		game->player_img->instances[0].x -= PIXELS;
	else if ((key.key == MLX_KEY_RIGHT || key.key == MLX_KEY_D)
		&& key.action == MLX_RELEASE)
		game->player_img->instances[0].x += PIXELS;
	else if ((key.key == MLX_KEY_UP || key.key == MLX_KEY_W)
		&& key.action == MLX_RELEASE)
		game->player_img->instances[0].y -= PIXELS;
	else if ((key.key == MLX_KEY_DOWN || key.key == MLX_KEY_S)
		&& key.action == MLX_RELEASE)
		game->player_img->instances[0].y += PIXELS;
}

void	open_window(t_game game)
{
	mlx_t			*mlx;
	t_imgs			pics;
	mlx_image_t		*backdrop;

	mlx = mlx_init(game.map.width * PIXELS, ((game.map.height + 2) * PIXELS),
			"so_long", false);
	if (mlx == NULL)
		ft_error("MLX error\n");
	pics = set_images(mlx);
	fill_backdrop(mlx, pics, &game);
	parse_map(mlx, pics, &game);
	backdrop = mlx_new_image(mlx, game.map.width * PIXELS, 2 * PIXELS);
	ft_memset(backdrop->pixels, 255,
		backdrop-> width * backdrop->height * sizeof(int));
	mlx_image_to_window(mlx, backdrop, 0, (game.map.height) * PIXELS);
	mlx_key_hook(mlx, &key_hooks, &game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
