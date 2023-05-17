/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   food.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 18:26:18 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/17 19:06:37 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_food(t_game	*game, int index)
{
	int		i;
	t_foods	*temp;

	temp = game->foods;
	i = 0;
	while (temp != NULL && i < index)
	{
		temp = temp -> next;
		i++;
	}
	return (temp->path);
}

void	add_food(t_foods **foods, t_foods *new)
{
	t_foods	*last;

	last = *foods;
	if (*foods == NULL)
	{
		new -> next = NULL;
		*foods = new;
	}
	else
	{
		while (last -> next != NULL)
			last = last -> next;
		new -> next = NULL;
		last -> next = new;		
	}
}

t_foods	*new_food(char *path)
{
	t_foods	*node;

	node = malloc(sizeof(t_foods));
	if (node == NULL)
		ft_error("Malloc\n");
	node -> path = path;
	node -> next = NULL;
	return (node);
}

void	set_foods(t_game *game)
{
	t_foods	*foods;
	
	game->foods = NULL;
	foods = NULL;
	add_food(&foods, new_food("textures/food_48/apple1.png"));
	add_food(&foods, new_food("textures/food_48/apple2.png"));
	add_food(&foods, new_food("textures/food_48/apple3.png"));
	add_food(&foods, new_food("textures/food_48/apple4.png"));
	add_food(&foods, new_food( "textures/food_48/grape1.png"));
	add_food(&foods, new_food( "textures/food_48/grape2.png"));
	add_food(&foods, new_food( "textures/food_48/grape3.png"));
	add_food(&foods, new_food( "textures/food_48/peach.png"));
	add_food(&foods, new_food( "textures/food_48/pear1.png"));
	add_food(&foods, new_food( "textures/food_48/pear2.png"));
	add_food(&foods, new_food( "textures/food_48/mandarin.png"));
	game->foods = foods;
}