/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 12:46:09 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/06 01:55:22 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(char	**map)
{
	int	row;

	row = 0;
	while (map[row])
	{
		printf("%s\n", map[row]);
		row++;
	}
}

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

void	fill_background(mlx_t *mlx, mlx_image_t	*img, mlx_image_t *wall, char **map)
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
			if (map[height][width] == '0')
			{
				if (mlx_image_to_window(mlx, img, y, x) < 0)
       				ft_error("Image error\n");
			}
			else if (map[height][width] == '1')
			{
				if (mlx_image_to_window(mlx, wall, y, x) < 0)
       				ft_error("Image error\n");
			}
			width++;
			y += PIXELS;
		}
		x += PIXELS;
		height++;
	}
}

int	close_window(void)
{
	exit(1);
}

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == 256 && keydata.action == MLX_RELEASE)
		exit(1);
	param++;
	param--;
}

void	open_window(t_map map_data)
{
	mlx_t			*mlx;
	mlx_image_t		*wall;
	mlx_image_t		*free;
	int				height;
	
	height = 0;
	while (map_data.map[height])
		height++;
	mlx = mlx_init((ft_strlen(*(map_data.map)) * PIXELS), (height * PIXELS), "so_long", false);
	if (mlx == NULL)
		ft_error("MLX error\n");
	wall = get_picture(mlx, "textures/tiles/038.png");
	free = get_picture(mlx, "textures/tiles/171.png");
	mlx_key_hook(mlx, &key_hooks, NULL);
	fill_background(mlx, free, wall, map_data.map);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
