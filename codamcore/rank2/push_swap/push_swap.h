/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 12:51:44 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/24 13:14:16 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_ps
{
	t_stack	**stack_a;
	t_stack	**stack_b;
}	t_ps;

t_stack	*second_last_node(t_stack *stack);
t_stack	*last_node(t_stack *lst);
t_stack	*ft_pop(t_stack **stack);
t_stack	*new_node(int value, int index);
void	sort_5(t_stack **stack_a, t_stack **stack_b, int arg_len, int value);
void	ft_push(t_stack **stack_src, t_stack **stack_dst, char name);
void	handle_input(t_stack **stack_a, char **argv);
void	sort_big(t_ps swap, int i, int j, int arg_len);
void	add_node(t_stack **stack, t_stack *new);
void	ft_reverse_rotate(t_stack **stack);
void	ft_ps(t_stack **stack, char c);
void	ft_rotate(t_stack **stack);
void	sort_3(t_stack **stack);
void	empty_b(t_stack **stack_a, t_stack **stack_b);
void	ft_error(void);
void	leaks(void);
int		ft_atoi_max(const char *str);
int		stack_size(t_stack *stack);
int		ft_digit_str(char *str);
int		max_digit(int max_num);
int		is_sorted(t_stack **stack);

#endif
