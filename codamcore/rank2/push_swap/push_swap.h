/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 12:51:44 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/23 23:19:18 by Julia         ########   odam.nl         */
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

typedef struct s_temp
{
	int				value;
	int				original_position;
	int				new_position;
}	t_temp;

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_value
{
	int				value;
	int				original_position;
	int				new_position;
}	t_value;

typedef struct s_swap
{
	int		stack_size;
	int		max_len;
	t_stack	**stack_a;
	t_stack	**stack_b;
}	t_swap;

void	ft_reverse_rotate(t_stack **stack);
void	ft_rotate(t_stack **stack);
void	ft_swap(t_stack **stack, char c);
void	ft_push(t_stack **stack_src, t_stack **stack_dst, char name);
void	ft_add_node(t_stack **stack, t_stack *new);
void	leaks(void);
void	check_duplicates(t_temp	*stack, int arg_len);
t_stack	*second_last_node(t_stack *stack);
t_stack	*last_node(t_stack *lst);
t_stack	*make_node(t_temp input);
t_stack	*ft_pop(t_stack **stack);
int		max_digit(int	max_num);
int		ft_digit_str(char	*str);
int		ft_stacksize(t_stack *lst);
int		is_sorted(t_swap swap);
void	print_stack(t_stack *head);
void	empty_b(t_swap swap);
int		ft_atoi_long(const char *str);
void	handle_input(t_swap swap, char **argv, int *arg_len);
void	sort_big(t_swap swap, int i, int j, int arg_len);
void	sort_5(t_swap swap, int arg_len);
void	sort_3(t_stack	**stack);
void	ft_error(void);
void	add_node(t_stack **stack, t_stack *new);

#endif

