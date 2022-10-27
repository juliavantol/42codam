/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 12:50:03 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/27 13:05:17 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Adds the node ’new’ at the end of the list. */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst != NULL)
	{
		last = ft_lstlast(*lst);
		last -> next = new;
	}
}
