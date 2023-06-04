/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectibles.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 14:30:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/30 11:07:12 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Returns new collectible instance */
t_collect	*collectible(void *content)
{
	t_collect	*node;

	node = malloc(sizeof(t_collect));
	if (node == NULL)
		return (NULL);
	if (content == NULL)
		node->img = NULL;
	else
		node->img = content;
	node->found = false;
	node->next = NULL;
	return (node);
}

/* Add collectible to the linked list */
void	add_collectible(t_collect **collectibles, t_collect *new)
{
	t_collect	*last;

	last = *collectibles;
	if (*collectibles == NULL)
	{
		new->next = NULL;
		*collectibles = new;
	}
	else
	{
		while (last->next != NULL)
			last = last->next;
		new->next = NULL;
		last->next = new;
	}
}

/* Checks if player has found all collectibles */
int	check_status(t_game *game)
{
	t_collect	*head;

	head = *(&game->collectibles);
	if (head == NULL)
		return (0);
	while (head != NULL)
	{
		if (head->found != true)
			return (0);
		head = head->next;
	}
	return (1);
}

/* Sets the collectible the player has touched as found 
and sets it to invisible. If it was the last, open the exit */
void	found_collectible(t_game *game, int x, int y)
{
	t_collect		*head;
	mlx_image_t		*exit;

	head = *(&game->collectibles);
	if (head == NULL)
		return ;
	while (head != NULL)
	{
		if (x * PIXELS == head->img->instances[0].x
			&& y * PIXELS == head->img->instances[0].y)
		{
			head->img->enabled = false;
			head->found = true;
		}
		head = head->next;
	}
	if (check_status(game) == 1)
	{
		game->exit_img->enabled = false;
		exit = get_picture(game->mlx, "textures/fridge_open.png");
		put_image(game->mlx, exit, game->exit_img->instances[0].y,
			game->exit_img->instances[0].x);
	}
}

/* Puts a collectible on the map */
void	put_collectible(mlx_t *mlx, t_game *game, int x, int y)
{
	mlx_image_t		*img;
	t_collect		*temp;
	int				index;
	char			*path;

	index = rand() % 10;
	path = game->food_paths[index];
	img = get_picture(mlx, path);
	put_image(mlx, img, x, y);
	temp = collectible(img);
	add_collectible(&game->collectibles, temp);
}
