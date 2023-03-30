/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 12:51:44 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/30 17:09:45 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

char	**check_input(int argc, char	**argv);
t_node	*ft_newnode(int num);
t_node	*ft_lstnode(t_node *lst);
void	fill_stack(char	**input, t_node **stack);
void	leaks(void);
int		ft_digit_str(char	*str);
void	ft_addnode(t_node **stack, t_node *new);
void	ft_push(t_node **stack_src, t_node **stack_dst);
void	ft_swap(t_node **stack);

#endif