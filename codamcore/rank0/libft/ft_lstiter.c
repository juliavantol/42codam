/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 12:10:20 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/28 12:29:46 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Iterates the list ’lst’ and applies the function ’f’ on the content 
of each node.  lst: The address of a pointer to a node. f: The address of 
the function used to iterate on the list.*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (lst != 0 && f != 0)
	{
		temp = lst;
		while (temp)
		{
			f(temp -> content);
			temp = temp -> next;
		}
	}
}