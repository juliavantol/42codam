/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 12:46:09 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/06 00:09:57 by Julia         ########   odam.nl         */
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

void	fill_background(mlx_t *mlx, mlx_image_t	*img, char **map)
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
			width++;
			y += 70;
		}
		x += 70;
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

void	open_window(char **map)
{
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	int				height;
	
	height = 0;
	while (map[height])
		height++;
	mlx = mlx_init(((ft_strlen(*map) * 70) - 1), (height * 70), "so_long", true);
	if (mlx == NULL)
		ft_error("MLX error\n");
	// Load texture
	texture = mlx_load_png("textures/platformerGraphics/Tiles/liquidWater.png");
	if (!texture)
        ft_error("Texture error\n");
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
        ft_error("Image error\n");
	mlx_key_hook(mlx, &key_hooks, NULL);
	fill_background(mlx, img, map);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
