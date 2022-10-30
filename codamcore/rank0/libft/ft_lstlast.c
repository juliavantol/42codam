/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 12:28:03 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/30 21:08:08 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* lst: The beginning of the list. */
/* Returns the last node of the list. */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (lst != NULL)
	{
		while (temp -> next != NULL)
			temp = temp -> next;
	}
	return (temp);
}
