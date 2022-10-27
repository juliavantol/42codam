/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 12:10:32 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/27 12:26:33 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Counts the number of nodes in a list. */
/* Returns the count. lst: The beginning of the list. */

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		count;

	temp = lst;
	count = 0;
	while (temp != NULL)
	{
		temp = temp -> next;
		count++;
	}
	return (count);
}