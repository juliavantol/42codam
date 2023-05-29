/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectibles.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 14:30:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/29 14:40:00 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_collect	*new_list(void *content)
{
	t_collect	*node;

	node = malloc(sizeof(t_collect));
	if (node == NULL)
		return (NULL);
	if (content == NULL)
		node -> img = NULL;
	else
		node -> img = content;
	node -> found = false;
	node -> next = NULL;
	return (node);
}

void	add_collectible(t_collect **collectibles, t_collect *new)
{
	t_collect	*last;

	last = *collectibles;
	if (*collectibles == NULL)
	{
		new -> next = NULL;
		*collectibles = new;
	}
	else
	{
		while (last -> next != NULL)
			last = last -> next;
		new -> next = NULL;
		last -> next = new;
	}
}

int	check_status(t_game *game)
{
	t_collect	*head;

	head = *(&game->collectibles);
	if (head == NULL)
		return (0);
	while (head != NULL)
	{
		if (head -> found != true)
			return (0);
		head = head -> next;
	}
	return (1);
}

void	found_collectible(t_game *game, int x, int y)
{
	t_collect		*head;
	mlx_image_t		*exit;

	head = *(&game->collectibles);
	if (head == NULL)
		return ;
	while (head != NULL)
	{
		if (x * PIXELS == head->img->instances[0].x &&
			y * PIXELS == head->img->instances[0].y)
		{
			head->img->enabled = false;
			head->found = true;
		}
		head = head -> next;
	}
	if (check_status(game) == 1)
	{
		game->exit_img->enabled = false;
		exit = get_picture(game->mlx, "textures/FRIDGE_OPEN2.png");
		put_image(game->mlx, exit, game->exit_img->instances[0].y,
			game->exit_img->instances[0].x);
	}
}

void	set_collectible_paths(t_game *game)
{
	char	**food_paths;

	food_paths = (char **)malloc(11 * sizeof(char *));
	if (!food_paths)
		ft_error("Malloc\n");
	food_paths[0] = "textures/food_48/apple1.png";
	food_paths[1] = "textures/food_48/apple2.png";
	food_paths[2] = "textures/food_48/apple3.png";
	food_paths[3] = "textures/food_48/apple4.png";
	food_paths[4] = "textures/food_48/grape1.png";
	food_paths[5] = "textures/food_48/grape2.png";
	food_paths[6] = "textures/food_48/grape3.png";
	food_paths[7] = "textures/food_48/pear1.png";
	food_paths[8] = "textures/food_48/pear2.png";
	food_paths[9] = "textures/food_48/mandarin.png";
	game->food_paths = food_paths;
}

void	put_collectible(mlx_t *mlx, t_game *game, int x, int y)
{
	mlx_image_t		*img;
	t_collect		*temp;
	int				index;
	char			*path;

	index = rand() % 11;
	path = game->food_paths[index];
	img = get_picture(mlx, path);
	put_image(mlx, img, x, y);
	temp = new_list(img);
	add_collectible(&game->collectibles, temp);
}
