/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 12:51:44 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/18 13:32:20 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_stack2
{
	int				value;
	int				original_position;
	int				new_position;
	struct s_stack2	*next;
}	t_stack2;

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_stack;

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
void	ft_swap(t_stack **stack);
void	ft_push(t_stack **stack_src, t_stack **stack_dst, char name);
void	ft_add_node(t_stack **stack, t_stack *new);
void	ft_sort(t_swap swap, int i, int j);
void	ft_simplify_input(char **input, int arg_len, t_stack **stack);
void	small_sort(t_stack	**stack, int first, int second);
void	small_sort_5(t_swap swap);
void	leaks(void);
char	**check_input(int argc, char	**argv, int	*arg_len);
void	check_dups(t_value	*indexed_nums, int arg_len);
void	parse_input(char	**argv, int count, int index);
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

void	add_node(t_stack2 **stack, t_stack2 *new);
t_stack2	*new_node(int value, int position);
t_stack2	*last_node(t_stack2 *stack);
void	print_stack2(t_stack2 *head, int count);


#endif
