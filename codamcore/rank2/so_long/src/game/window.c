/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 12:46:09 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/29 23:49:59 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Display the current amount of moves on the screen */
void	display_moves(mlx_t *mlx, t_game *game)
{
	char	*str;
	char	*temp;

	temp = ft_itoa(game->moves);
	if (!temp)
		ft_error("Itoa\n");
	str = ft_strjoin(" Moves: ", temp);
	if (!str)
		ft_error("Strjoin\n");
	mlx_delete_image(game->mlx, game->display);
	game->display = mlx_put_string(mlx, str, 0, (game->map.height) * PIXELS);
	if (!game->display)
		ft_error("Mlx string\n");
	free(temp);
	free(str);
}

/* Fills the backdrop with the floor image */
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
			put_image(mlx, pics.floor, x * PIXELS, y * PIXELS);
			y++;
		}
		x++;
	}
}

/* Parses the map to the window */
void	parse_map(mlx_t *mlx, t_imgs pics, t_game *game, int x)
{
	int	y;

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

/* Listens to the player's input */
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
	if (key.action == MLX_PRESS || key.action == MLX_REPEAT)
		prepare_move(game, key, x, y);
}

/* Opens up a window and starts the game */
void	open_window(t_game game)
{
	mlx_image_t		*backdrop;
	t_imgs			pics;

	game.mlx = mlx_init(game.map.width * PIXELS,
			((game.map.height + 1) * PIXELS), "so_long", false);
	if (game.mlx == NULL)
		ft_error("MLX error\n");
	pics = set_images(game.mlx);
	fill_backdrop(game.mlx, pics, &game);
	parse_map(game.mlx, pics, &game, 0);
	spawn_enemies(&game);
	display_moves(game.mlx, &game);
	backdrop = mlx_new_image(game.mlx, game.map.width * PIXELS, 1 * PIXELS);
	ft_memset(backdrop->pixels, 0,
		backdrop-> width * backdrop->height * sizeof(int));
	mlx_image_to_window(game.mlx, backdrop, 0, (game.map.height) * PIXELS);
	mlx_key_hook(game.mlx, &key_hooks, &game);
	mlx_loop_hook(game.mlx, move_enemies, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}
