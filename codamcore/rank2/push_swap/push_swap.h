/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 12:51:44 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/22 11:45:36 by juvan-to      ########   odam.nl         */
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

void	ft_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate(t_stack **stack);
void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack);
void	ft_swap_both(t_stack **stack_a, t_stack **stack_b);
void	ft_swap(t_stack **stack, char c);
void	ft_push(t_stack **stack_src, t_stack **stack_dst, char name);
void	ft_add_node(t_stack **stack, t_stack *new);
void	ft_sort(t_swap swap, int i, int j, int arg_len);
void	ft_simplify_input(char **input, int arg_len, t_stack **stack);
void	small_sort(t_stack	**stack, int first, int second, int third);
void	small_sort_5(t_swap swap, int arg_len);
void	leaks(void);
char	**check_input(int argc, char	**argv, int	*arg_len);
void	check_dups(t_value	*indexed_nums, int arg_len);
t_stack	*ft_secondlast(t_stack *stack);
t_stack	*ft_last(t_stack *lst);
t_stack	*ft_make_node(int num);
t_stack	*ft_pop(t_stack **stack);
int		max_digit(int	max_num);
int		ft_digit_str(char	*str);
int		ft_stacksize(t_stack *lst);
int		is_sorted(t_swap swap);
void	print_stack(t_stack *head);
void	empty_b(t_swap swap);
t_stack	*ft_make_node2(int num);
void	rev_sort_3(t_stack	**stack);
int		ft_atoi_long(const char *str);
t_temp	*handle_input(char	**argv, int *arg_len);
void	fill_stack2(t_temp *input, t_stack **stack, int arg_len);
void	ft_error(void);
void	print_stack_i(t_stack *head);

#endif

