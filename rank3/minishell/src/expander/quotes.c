/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quotes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/24 18:09:16 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/26 00:33:06 by Julia         ########   odam.nl         */
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

char	*handle_quotes(char *str, char *output, int i, int j)
{
	char	inside_quote;
	int		len;

	len = ft_strlen(str);
	inside_quote = '\0';
	output = ft_malloc((len * sizeof(char)) + 1);
	while (i < len)
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			if (inside_quote == '\0')
				inside_quote = str[i];
			else if (inside_quote == str[i])
				inside_quote = '\0';
			else
				output[j++] = str[i];
		}
		else
			output[j++] = str[i];
		i++;
	}
	output[j] = '\0';
	return (output);
}
