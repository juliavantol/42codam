/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 11:45:25 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/30 21:10:21 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a new node. The member variable 
’content’ is initialized with the value of the parameter ’content’. 
The variable ’next’ is initialized to NULL.*/
/* Returns the new node */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}
