/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 12:46:09 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/08 13:03:32 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

mlx_image_t	*get_picture(mlx_t *mlx, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	// Load texture
	texture = mlx_load_png(path);
	if (!texture)
        ft_error("Texture error\n");
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
        ft_error("Image error\n");
	return (img);
}

t_imgs	set_images(mlx_t *mlx)
{
	t_imgs	pics;

	pics.floor = get_picture(mlx, "textures/tile_32/00.png");
	pics.wall = get_picture(mlx, "textures/ice_32/113.png");
	pics.player_front = get_picture(mlx, "textures/ghosts/front.png");
	pics.player_back = get_picture(mlx, "textures/ghosts/back.png");
	pics.player_left = get_picture(mlx, "textures/ghosts/left.png");
	pics.player_right = get_picture(mlx, "textures/ghosts/right.png");
	pics.collectible = get_picture(mlx, "textures/porb2.png");
	pics.exit = get_picture(mlx, "textures/exitstone.png");
	return (pics);
}

void	put_image(mlx_t *mlx, mlx_image_t *img, int x, int y)
{
	if (mlx_image_to_window(mlx, img, y, x) < 0)
       	ft_error("Image error\n");
}

void	delete_image(mlx_t *mlx, mlx_image_t *img)
{
	mlx_delete_image(mlx, img);
}

void	parse_map(mlx_t *mlx, t_imgs pics, char **map)
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

void	fill_background(mlx_t *mlx, t_imgs pics, char **map, t_game *game)
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

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == 256 && keydata.action == MLX_RELEASE)
		exit(1);
	if (keydata.key == 263 && keydata.action == MLX_RELEASE)
		((t_game *)param)->player_img->instances[0].x -= PIXELS;
	if (keydata.key == 262 && keydata.action == MLX_RELEASE)
		((t_game *)param)->player_img->instances[0].x += PIXELS;
	if (keydata.key == 265 && keydata.action == MLX_RELEASE)
		((t_game *)param)->player_img->instances[0].y -= PIXELS;
	if (keydata.key == 264 && keydata.action == MLX_RELEASE)
		((t_game *)param)->player_img->instances[0].y += PIXELS;
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
	parse_map(mlx, pics, map_data.map);
	fill_background(mlx, pics, map_data.map, &game);
	// printf("x: %d and y: %d\n", game.player_x, game.player_y);
	// printf("test: %d\n", game.player_img->instances[0].y);
	mlx_key_hook(mlx, &key_hooks, &game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
