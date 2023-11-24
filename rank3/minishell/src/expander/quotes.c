/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quotes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/24 18:09:16 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/24 18:56:54 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*remove_quotes(char *str, char quote, int i, int j)
{
	int	k;

	while (str[i])
	{
		if (str[i] == quote)
		{
			j = i;
			k = i;
			while (str[j] == quote)
				j++;
			while (str[j])
			{
				str[k] = str[j];
				k++;
				j++;
			}
			str[k] = '\0';
		}
		else
			i++;
	}
	return (str);
}

bool	is_str_enclosed_by_quotes(char *str, char quote)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	if (len < 2)
		return (false);
	if (str[0] != quote || str[len - 1] != quote)
		return (false);
	while (i < len - 1)
	{
		if (str[i] == quote && str[i + 1] != quote)
			return (true);
		i++;
	}
	return (false);
}

int	quote_len(char *str, int index, int quote)
{
	int	len;

	len = 0;
	while (str[index] && str[index] == quote)
	{
		len++;
		index++;
	}
	return (len);
}

// keep copying into new output until double quoted found, then go to a function
void	handle_quotes(char *str, char quote)
{
	int		index;
	char	*output;
	char	*temp_str;
	char	*temp;

	output = ft_strdup("");
	index = 0;
	while (str[index])
	{
		if (str[index] == quote)
			index += quote_len(str, index, quote);
		temp = output;
		temp_str = char_to_str(str[index]);
		output = join_three_strs(temp, NULL, temp_str);
		free(temp);
		free(temp_str);
		index++;
	}
	printf("%s\n", output);
	free(output);
	quote--;
}
