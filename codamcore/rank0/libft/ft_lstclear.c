/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 11:49:14 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/30 22:18:08 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Deletes and frees the given node and every successor of that node, 
using the function ’del’ and free(3). Finally, the pointer to the list 
must be set to NULL. */

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*next;

	if (*lst != 0 && del != 0)
	{
		temp = *lst;
		while (temp)
		{
			next = temp -> next;
			ft_lstdelone(temp, del);
			temp = next;
		}
		*lst = 0;
	}
}
