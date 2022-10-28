/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 11:27:30 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/28 11:48:17 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Takes as a parameter a node and frees the memory of the node’s content 
using the function ’del’ given as a parameter and free the node. The memory 
of ’next’ must not be freed. */
/* lst: The node to free. del: The address of the function used to delete
the content. */

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != 0 && del != 0)
	{
		del(lst -> content);
		free(lst);
	}
}
