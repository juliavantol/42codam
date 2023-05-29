/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:30:42 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/29 23:21:37 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>

# define PIXELS 48
# define ENEMY_SPEED 30

typedef struct s_collect
{
	mlx_image_t			*img;
	bool				found;
	struct s_collect	*next;
}	t_collect;

typedef struct s_mouse
{
	mlx_image_t		*img;
	int				x;
	int				y;
	struct s_mouse	*next;
}	t_mouse;

typedef struct s_tile
{
	int				x;
	int				y;
	bool			enemy;
	struct s_tile	*next;
}	t_tile;

typedef struct s_map
{
	t_tile		*free_tiles2;
	char		*file_name;
	char		**map;
	int			collectibles;
	int			free_tiles;
	int			width;
	int			height;
	int			file;
	int			exit_x;
	int			exit_y;
	int			exit;
	int			start_x;
	int			start_y;
	int			start;
}	t_map;

typedef struct s_imgs
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player_front;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
}	t_imgs;


typedef struct s_game
{
	mlx_image_t	*player_img;
	mlx_image_t	*exit_img;
	mlx_image_t	*display;
	t_mouse		*mice;
	t_collect	*collectibles;
	t_imgs		*pics;
	t_map		map;
	mlx_t		*mlx;
	char		**food_paths;
	char		**temp_grid;
	char		direction;
	int			moves;
	int			runs;
	int			loop;
	bool		won;
}	t_game;

t_map		check_characters(t_map map, int length, char *temp, char *line);
t_game		init_game(int file, char *filename);
mlx_image_t	*get_picture(mlx_t *mlx, char *path);
t_collect	*collectible(void *content);
t_imgs		set_images(mlx_t *mlx);

int			check_walls(t_game game, int i, int j);
int			check_move(t_game *game, int key);
int			check_status(t_game *game);
int			if_empty_line(char *str);
int			close_window(void);

char		**ft_split_sl(char const *s, char c);
char		**fill_map(t_map map_data);

void		valid_character(t_map *data, char *line, int height, int index);
void		prepare_move(t_game *game, mlx_key_data_t key, int x, int y);
void		add_collectible(t_collect **collectibles, t_collect *new);
void		add_tile(t_map *data, t_tile **free_tiles, int x, int y);
void		put_collectible(mlx_t *mlx, t_game *game, int x, int y);
void		animate_player(t_game *game, char *path, int x, int y);
void		put_image(mlx_t *mlx, mlx_image_t *img, int x, int y);
void		move_player(t_game *game, char	*path, int x, int y);
void		try_move(t_mouse *mouse, t_game *game, int i, int j);
void		found_collectible(t_game *game, int x, int y);
void		add_enemy(t_game *game, mlx_image_t *img);
void		display_moves(mlx_t *mlx, t_game *game);
void		check_path_collectibles(t_game *game);
void		check_path(t_map map, t_game *game);
void		put_enemy(mlx_t *mlx, int x, int y);
void		set_collectible_paths(t_game *game);
void		check_path_enemies(t_game *game);
void		free_map(char	**map, int max);
void		check_collision(t_game	*game);
void		spawn_enemies(t_game *game);
void		open_window(t_game game);
void		move_enemies(void *data);
void		stop_game(t_game *game);
void		set_foods(t_game *game);
void		ft_error(char *str);

#endif
