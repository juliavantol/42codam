/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simplify.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 13:15:48 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/07 13:31:32 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insertion_sort(t_value	*indexed_nums, int arg_len)
{
	int		index;
	int		j;
	t_value	temp;

	index = 1;
	while (index < arg_len)
	{
		j = index;
		while (j > 0 && indexed_nums[j].value < indexed_nums[j - 1].value)
		{
			temp = indexed_nums[j];
			indexed_nums[j] = indexed_nums[j - 1];
			indexed_nums[j - 1] = temp;
			j--;
		}
		index++;
	}
	index = 0;
	while (index < arg_len)
	{
		indexed_nums[index].new_position = index;
		index++;
	}
}

static int	search_num(t_value	*indexed_nums, int arg_len, int original)
{
	int	index;

	index = 0;
	while (index < arg_len)
	{
		if (indexed_nums[index].original_position == original)
			return (indexed_nums[index].new_position);
		index++;
	}
	return (-1);
}

static void	fill_stack(t_value	*indexed_nums, t_node **stack, int arg_len)
{
	int	index;
	int	num;

	index = 0;
	while (index < arg_len)
	{
		num = search_num(indexed_nums, arg_len, index);
		ft_add_node(stack, ft_make_node(num));
		index++;
	}
	free(indexed_nums);
}

void	ft_simplify_input(char **input, int arg_len, t_node **stack)
{
	int		index;
	t_value	*indexed_nums;
	t_value	*temp;

	index = 0;
	indexed_nums = malloc(arg_len * sizeof(t_value));
	if (!indexed_nums)
		exit(1);
	while (index < arg_len)
	{
		temp = malloc(sizeof(t_value));
		if (!temp)
			exit(1);
		temp -> value = ft_atoi(input[index]);
		temp -> original_position = index;
		indexed_nums[index] = *temp;
		index++;
		free(temp);
	}
	insertion_sort(indexed_nums, arg_len);
	fill_stack(indexed_nums, stack, arg_len);
}
