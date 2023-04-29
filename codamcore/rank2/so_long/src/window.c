/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 12:46:09 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/29 15:23:20 by juvan-to      ########   odam.nl         */
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
	param = NULL;
}

void	open_window(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(1920, 1080, "Hello world!", true);
	if (mlx == NULL)
		ft_error("MLX error\n");
	mlx_key_hook(mlx, &key_hooks, NULL);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
