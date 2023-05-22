/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:30:42 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/22 14:29:27 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>

# define PIXELS 48

typedef struct s_node
{
	mlx_image_t		*img;
	bool			found;
	struct s_node	*next;
}	t_node;

typedef struct s_mouse
{
	mlx_image_t		*img;
	struct s_mouse	*next;
}	t_mouse;

typedef struct s_map
{
	int		file;
	char	*file_name;
	char	**map;
	int		width;
	int		height;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		start;
	int		start_x;
	int		start_y;
	int		collectibles;
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

typedef struct s_foods
{
	char			*path;
	struct s_foods	*next;
}	t_foods;

typedef struct s_game
{
	mlx_image_t	*player_img;
	t_node		*collectibles;
	t_foods		*foods;
	t_imgs		*pics;
	t_map		map;
	bool		won;
	int			moves;
	mlx_image_t	*display;
	mlx_t		*mlx;
	char		**temp_grid;
	int			exit[2];
	t_mouse		*mice;
}	t_game;

void		ft_error(char *str);
int			if_empty_line(char *str);
void		open_window(t_game game);
int			close_window(void);
char		**fill_map(t_map map_data);
void		print_map(char **map);
t_imgs		set_images(mlx_t *mlx);
void		put_image(mlx_t *mlx, mlx_image_t *img, int x, int y);
int			check_move(t_game *game, int key);
t_node		*new_list(void *content);
void		add_collectible(t_node **collectibles, t_node *new);
mlx_image_t	*get_picture(mlx_t *mlx, char *path);
void		print_list(t_node **collectibles);
void		found_collectible(t_game *game, int x, int y);
int			check_status(t_game *game);
void		display_moves(mlx_t *mlx, t_game *game);
void		check_path(t_map map, t_game *game);
void		print_collectibles(t_game game);
void		check_path_collectibles(t_game *game);
void		put_collectible(mlx_t *mlx, t_game *game, int x, int y);

void		valid_character(t_map *data, char *line, int height, int index);
t_map		check_characters(t_map map, int length);
t_game		init_game(int file, char *filename);
int			check_walls(t_game game, int i, int j);
void		free_map(char	**map, int max);
void		stop_game(t_game *game);
char		**ft_split_sl(char const *s, char c);
void		move_player(t_game *game, char	*path, int x, int y);
void		set_foods(t_game *game);
t_foods		*new_food(char *path);
char		*get_food(t_game	*game, int index);
void		put_enemy(mlx_t *mlx, int x, int y);
void		add_enemy(t_game *game, mlx_image_t *img);
void		add_enemies(t_game *game);
void		move_enemies(t_game *game);

#endif