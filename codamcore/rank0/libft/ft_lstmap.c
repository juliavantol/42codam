/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 12:39:18 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/28 14:26:38 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Iterates the list ’lst’ and applies the function ’f’ on the content 
of each node. Creates a new list resulting of the successive applications 
of the function ’f’. The ’del’ function is used to delete the content 
of a node if needed. Returns the new list. NULL if the allocation fails. */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*results;

	results = 0;
	if (lst != 0 && f != 0 && del != 0)
	{
		while (lst)
		{
			new = ft_lstnew((f(lst -> content)));
			if (new == NULL)
			{
				ft_lstclear(results -> content, del);
				return (NULL);
			}
			ft_lstadd_back(&results, new);
			lst = lst -> next;
		}
		return (results);
	}
	return (NULL);
}
