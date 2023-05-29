/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 14:12:58 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/29 13:08:41 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*get_picture(mlx_t *mlx, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
	{
		printf("path: %s\n", path);
		ft_error("Texture error\n");
	}
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		ft_error("Image error\n");
	mlx_delete_texture(texture);
	return (img);
}

t_imgs	set_images(mlx_t *mlx)
{
	t_imgs	pics;

	pics.floor = get_picture(mlx, "textures/light_wood.png");
	pics.wall = get_picture(mlx, "textures/dark_wood.png");
	pics.player_front = get_picture(mlx, "textures/grandma/down2.png");
	pics.exit = get_picture(mlx, "textures/FRIDGE_CLOSE2.png");
	return (pics);
}

void	put_image(mlx_t *mlx, mlx_image_t *img, int x, int y)
{
	if (mlx_image_to_window(mlx, img, y, x) < 0)
		ft_error("Image error\n");
}
