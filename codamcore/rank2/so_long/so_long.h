/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:30:42 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/09 14:00:35 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "include/libft/libft.h"
# include "include/get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"

# define PIXELS 32

typedef struct s_map
{
	char	*file;
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_imgs
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player_front;
	mlx_image_t	*player_back;
	mlx_image_t	*player_left;
	mlx_image_t	*player_right;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
}	t_imgs;

typedef struct s_game
{
	mlx_image_t	*player_img;
	t_map		map;
}	t_game;

void	ft_error(char *str);
t_map	check_map(int map, int start, int exit, int collectible);
int		if_empty_line(char *str);
void	open_window(t_map map_data, int width);
int		close_window(void);
char	**fill_map(t_map map_data);
void	print_map(char **map);
t_imgs	set_images(mlx_t *mlx);
void	put_image(mlx_t *mlx, mlx_image_t *img, int x, int y);
int		check_move(t_game *game, int key);

#endif