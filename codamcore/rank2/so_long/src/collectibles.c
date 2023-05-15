/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectibles.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 14:30:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/15 12:08:51 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	print_collectibles(t_game game)
// {
// 	t_node	*temp;

// 	temp = game.collectibles;
// 	while(temp)
// 	{
// 		printf("%d - %d\n", temp->x, temp->y);
// 		temp = temp -> next;
// 	}
// }

t_node	*new_list(void *content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	if (content == NULL)
		node -> img = NULL;
	else
		node -> img = content;
	node -> found= false;
	node -> next = NULL;
	return (node);
}

void	add_collectible(t_node **collectibles, t_node *new)
{
	t_node	*last;

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

int		check_status(t_game *game)
{
	t_node	*head;

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
	t_node	*head;

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
}

void	put_collectible(mlx_t *mlx, t_game *game, int x, int y)
{
	mlx_image_t		*img;
	t_node			*temp;

	img = get_picture(mlx, "textures/porb2.png");
	put_image(mlx, img, x, y);
	temp = new_list(img);
	add_collectible(&game->collectibles, temp);	
}

void	get_collectibles(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	while (x < game->map.height)
	{
		y = 0;
		while (y < game->map.width)
		{
			if (game->map.map[x][y] == 'C')
			{
				if (game->temp_grid[x][y] != '1')
					ft_error("No valid path\n");
			}
			y++;
		}
		x++;
	}
}