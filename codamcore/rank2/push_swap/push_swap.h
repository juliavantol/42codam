/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 12:51:44 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/07 13:31:54 by juvan-to      ########   odam.nl         */
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

typedef struct s_value
{
	int				value;
	int				original_position;
	int				new_position;
}	t_value;

void	ft_reverse_rotate_both(t_node **stack_a, t_node **stack_b);
void	ft_reverse_rotate(t_node **stack);
void	ft_rotate_both(t_node **stack_a, t_node **stack_b);
void	ft_rotate(t_node **stack);
void	ft_swap_both(t_node **stack_a, t_node **stack_b);
void	ft_swap(t_node **stack);
void	ft_push(t_node **stack_src, t_node **stack_dst);
void	ft_add_node(t_node **stack, t_node *new);
void	ft_sort(t_node **stack, int max_len);
void	ft_simplify_input(char **input, int arg_len, t_node **stack);
void	leaks(void);
char	**check_input(int argc, char	**argv, int	*arg_len);
t_node	*ft_secondlast(t_node *stack);
t_node	*ft_last(t_node *lst);
t_node	*ft_make_node(int num);
t_node	*ft_pop(t_node **stack);
int		max_digit(t_node	*stack);
int		ft_digit_str(char	*str);
int		ft_stacksize(t_node *lst);

#endif