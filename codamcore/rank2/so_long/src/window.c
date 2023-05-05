/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 12:46:09 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/05 12:39:36 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(void)
{
	exit(1);
}

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == 256 && keydata.action == MLX_RELEASE)
		exit(1);
	param--;
}

void	open_window(void)
{
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	mlx = mlx_init(1920, 1080, "Hello world!", true);
	if (mlx == NULL)
		ft_error("MLX error\n");
	// Load texture
	texture = mlx_load_png("textures/platformerGraphics/Tiles/liquidWater.png");
	if (!texture)
        ft_error("Texture error\n");
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
        ft_error("Image error\n");
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
    	ft_error("Image error\n");
	mlx_key_hook(mlx, &key_hooks, NULL);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
