/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_str.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 22:46:55 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/22 00:07:34 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*expand_string(t_exe *executor, char *input_str)
{
	char	*output;

	output = ft_strdup("");
	needs_expansion(input_str, 0);
	printf("after: [%s]\n", output);
	return (output);
	printf("%s\n", executor->paths[0]);
}
