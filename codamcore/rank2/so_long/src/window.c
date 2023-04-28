/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 12:46:09 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/28 14:27:46 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(void)
{
	exit(1);
}

int	handle_no_event(void *data)
{
	data = NULL;
	return (0);
}

int	handle_input(int keysym, t_mlx *data)
{
	printf("Keypress: %d\n", keysym);
	if (keysym == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (1);
	}
	return (0);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	open_window(void)
{
	t_data	img;
	t_mlx	vars;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		ft_error("mlx error");
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	if (vars.win == NULL)
		ft_error("mlx error");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	put_pixel(&img, 100, 100, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop_hook(vars.mlx, &handle_no_event, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_key_hook(vars.win, &handle_input, &vars);
	mlx_loop(vars.mlx);
}
