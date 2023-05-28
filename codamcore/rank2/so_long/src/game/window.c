/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 12:46:09 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/28 17:38:08 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves(mlx_t *mlx, t_game *game)
{
	char	*str;
	char	*temp;

	if (game->display != NULL)
		game->display->enabled = false;
	temp = ft_itoa(game->moves);
	if (!temp)
		ft_error("itoa\n");
	str = ft_strjoin(" Moves: ", temp);
	if (!str)
		ft_error("strjoin\n");
	game->display = mlx_put_string(mlx, str, 0, (game->map.height) * PIXELS);
	game->display->enabled = true;
	game->moves += 1;
	free(temp);
	free(str);
}

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
			{
				put_image(mlx, pics.exit, x * PIXELS, y * PIXELS);
				game->exit_img = pics.exit;
			}
			y++;
		}
		x++;
	}
}

void	key_hooks(mlx_key_data_t key, void *data)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *)data;
	x = game->player_img->instances[0].x;
	y = game->player_img->instances[0].y;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
	if (check_move(game, key.key) == 0)
		return ;
	else if (key.action == MLX_RELEASE || key.action == MLX_REPEAT)
		display_moves(game->mlx, game);
	if (key.action == MLX_PRESS || key.action == MLX_REPEAT)
		prepare_move(game, key, x, y);
}

void	open_window(t_game game)
{
	mlx_t			*mlx;
	mlx_image_t		*backdrop;
	t_imgs			pics;

	mlx = mlx_init(game.map.width * PIXELS, ((game.map.height + 1) * PIXELS),
			"so_long", false);
	if (mlx == NULL)
		ft_error("MLX error\n");
	pics = set_images(mlx);
	game.mlx = mlx;
	game.display = NULL;
	game.loop = 1;
	game.direction = 'd';
	game.mice = NULL;
	fill_backdrop(mlx, pics, &game);
	parse_map(mlx, pics, &game);
	spawn_enemies(&game);
	// add_enemies(&game);
	display_moves(game.mlx, &game);
	backdrop = mlx_new_image(mlx, game.map.width * PIXELS, 1 * PIXELS);
	ft_memset(backdrop->pixels, 0,
		backdrop-> width * backdrop->height * sizeof(int));
	mlx_image_to_window(mlx, backdrop, 0, (game.map.height) * PIXELS);
	mlx_key_hook(mlx, &key_hooks, &game);
	mlx_loop_hook(mlx, move_enemies, &game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
