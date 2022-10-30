/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 12:39:18 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/30 21:10:32 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Iterates the list ’lst’ and applies the function ’f’ on the content 
of each node. Creates a new list resulting of the successive applications 
of the function ’f’. The ’del’ function is used to delete the content 
of a node if needed. Returns the new list. NULL if the allocation fails. */

static int	null(void *input, t_list *output, void (*del)(void *))
{
	if (input == NULL)
	{
		ft_lstclear(output -> content, del);
		return (1);
	}
	else
		return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*output;
	void	*res;

	if (lst == NULL || *f == NULL || del == NULL)
		return (NULL);
	output = NULL;
	if (lst != 0 && f != 0 && del != 0)
	{
		while (lst)
		{
			res = (*f)(lst->content);
			new = ft_lstnew(res);
			if (null(res, output, del) == 1 || null(new, output, del) == 1)
				return (NULL);
			ft_lstadd_back(&output, new);
			lst = lst -> next;
		}
		return (output);
	}
	return (NULL);
}
