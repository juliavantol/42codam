/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 12:51:44 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/24 17:52:18 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

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
	int		arg_len;
}	t_ps;

void	ft_push(t_stack **stack_src, t_stack **stack_dst, char name);
void	handle_input(t_stack **stack_a, char **argv);
void	sort_big(t_ps ps, int i, int j, int max_digit);
void	empty_b(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_ps ps, int index, int value);
void	sort_3(t_stack **stack);
void	add_node(t_stack **stack, t_stack *new);
void	ft_reverse_rotate(t_stack **stack);
void	ft_swap(t_stack **stack, char c);
void	ft_rotate(t_stack **stack);
void	ft_error(void);
int		is_sorted(t_stack **stack);
int		ft_atoi_max(char *str);
int		stack_size(t_stack *stack);
int		ft_digit_str(char *str);
int		max_digit(int max_num);
t_stack	*second_last_node(t_stack *stack);
t_stack	*new_node(int value, int index);
t_stack	*last_node(t_stack *lst);
t_stack	*ft_pop(t_stack **stack);

#endif
