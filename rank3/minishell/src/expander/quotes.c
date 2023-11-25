/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quotes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/24 18:09:16 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/25 23:52:05 by Julia         ########   odam.nl         */
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

// int	loop_until_quote(char *str, char quote, int index)
// {
// 	while (str[index] && str[index] != quote)
// 	{
// 		index++;
// 	}
// 	return (output_index);
// }

int	quote_len(char *str, int index, int quote)
{
	int	len;

	len = 0;
	while (str[index] && str[index] == quote)
		index++;
	while (str[index] && str[index] != quote)
	{
		len++;
		index++;
	}
	return (len);
}

char	*copy_until_quote(char *str, int index, int len, int quote)
{
	char	*output;
	char	*temp_str;
	char	*temp;
	int		i;

	i = 0;
	output = ft_strdup("");
	while (str[index] && str[index] == quote)
		index++;
	while (str[index] && i < len && str[index] != quote)
	{
		temp = output;
		temp_str = char_to_str(str[index]);
		output = join_three_strs(temp, NULL, temp_str);
		free(temp);
		free(temp_str);
		index++;
	}
	printf("%s\n", output);
	return (output);
}

int	loop_until_quote(char *str, char quote, int index)
{
	char	*quote_str;
	char	*temp;
	int		output_index;

	output_index = index;
	quote_str = ft_strdup("");
	while (str[index] && str[index] == quote)
	{
		temp = quote_str;
		quote_str = join_three_strs(quote_str, NULL, char_to_str(str[index]));
		free(temp);
		index++;
	}
	printf("%s\n", quote_str);
	exit(1);
	return (output_index);
}

char *handle_quotes2(char *str)
{
	char inside_quote = '\0';
    int i = 0, j = 0;
    int len = strlen(str);
    char *output = malloc(len + 1);

    while (i < len)
    {
        if (str[i] == '\'' || str[i] == '"')
        {
            if (inside_quote == '\0')  // 따옴표 밖에서 따옴표를 만났습니다.
            {
                inside_quote = str[i];  // 따옴표 안으로 들어갔습니다.
            }
            else if (inside_quote == str[i])  // 따옴표 안에서 같은 따옴표를 만났습니다.
            {
                inside_quote = '\0';  // 따옴표 밖으로 나왔습니다.
            }
            else
            {
                output[j++] = str[i];  // 다른 종류의 따옴표 안에서 따옴표를 만났습니다.
            }
        }
        else
        {
            output[j++] = str[i];  // 따옴표가 아닌 문자를 만났습니다.
        }
        i++;
    }
    output[j] = '\0';  // 결과 문자열의 끝을 표시합니다.
	printf("%s\n", output);
    return (output);
}

void	handle_quotes(char *str)
{
	int		index;
	int		temp_index;
	char	*output;
	char	*temp_str;
	char	*temp;

	handle_quotes2(str);
	exit(1);
	output = ft_strdup("");
	index = 0;
	while (str[index])
	{
		if (str[index] == '"' || str[index] == '\'')
		{
			temp_index = quote_len(str, index, str[index]);
			copy_until_quote(str, index, temp_index, str[index]);
			exit(1);
			index += temp_index;
		}
		else
		{
			temp = output;
			temp_str = char_to_str(str[index]);
			output = join_three_strs(temp, NULL, temp_str);
			free(temp);
			free(temp_str);
			index++;
		}
	}
	printf("%s\n", output);
	free(output);
}
