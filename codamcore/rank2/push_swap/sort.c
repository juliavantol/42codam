/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 17:13:57 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/07 12:10:06 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//make && ./push_swap "87 -487 781 -100 101 0 1"

void	ft_sort(t_node **stack, int	max_len)
{
	stack = NULL;
	printf("max: %d\n", max_len);
	printf("%d\n", 123 >> 10);
}

void	insertion_sort(t_value	*indexed_nums, int arg_len)
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
}

void	ft_simplify(char **input, int arg_len, t_node **stack)
{

	int		index;
	int		nums[arg_len];
	t_value	indexed_nums[arg_len];
	t_value	*new_value;

	index = 0;
	while (index < arg_len)
	{
		new_value = malloc(sizeof(new_value));
		new_value -> value = ft_atoi(input[index]);
		new_value -> original_position = index;
		new_value -> new_position = -1;
		indexed_nums[index] = *new_value;
		nums[index] = ft_atoi(input[index]);
		index++;
	}
	insertion_sort(indexed_nums, arg_len);
	index = 0;
	while (index < arg_len)
	{
		new_value = &indexed_nums[index];
		new_value -> new_position = index;
		index++;
	}
	index = 0;
	while (index < arg_len)
	{
		printf("%d -- %d -- %d\n", indexed_nums[index].value, indexed_nums[index].original_position, indexed_nums[index].new_position);
		index++;
	}
	printf("\n\n\n\n");
	stack = NULL;
}


// void	ft_simplify(char **input, int arg_len, t_node **stack)
// {

// 	int		index;
// 	int		temp_arr[arg_len][2];
// 	int		temp;
// 	int		temp2;
// 	int		j;
// 	index = 0;
// 	while (index < arg_len)
// 	{
// 		temp_arr[index][0] = ft_atoi(input[index]);
// 		temp_arr[index][1] = index;
// 		index++;
// 	}
// 	index = 0;
// 	while (index < arg_len)
// 	{
// 		printf("%d -- %d\n", temp_arr[index][0], temp_arr[index][1]);
// 		index++;
// 	}
// 	printf("\n\n\n\n");
// 	index = 1;
// 	while (index < arg_len)
// 	{
// 		j = index;
// 		while (j > 0 && temp_arr[j][0] < temp_arr[j - 1][0])
// 		{
// 			temp = temp_arr[j][0];
// 			temp2 = temp_arr[j][1];
// 			temp_arr[j][0] = temp_arr[j - 1][0];
// 			temp_arr[j][1] = temp_arr[j - 1][1];
// 			temp_arr[j - 1][0] = temp;
// 			temp_arr[j - 1][1] = temp2;
// 			j--;
// 		}
// 		index++;
// 	}

// 	index = 0;
// 	while (index < arg_len)
// 	{
// 		printf("%d -- %d\n", temp_arr[index][0], temp_arr[index][1]);
// 		ft_add_node(stack, ft_make_node(temp_arr[index++][1]));
// 	}
// }