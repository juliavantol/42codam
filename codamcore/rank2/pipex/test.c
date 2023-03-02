/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:17:48 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/02 15:53:23 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void count_words(char	*str, char	single, char dble, char space)
{
	int	index;
	int	i;
	int end;

	index = 0;
	end = 0;
	while (str[index])
	{
		i = index;
		while (str[i] && str[i] != dble && str[i] != single)
		{
			i++;
		}
		printf("\n%s\n", ft_substr(str, index, i));
		index = index + i + 1;
	}
	space--;
}

/* Returns the substring using the starting index of s and its len */
char	*word(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*word;

	index = 0;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	while (index < len && s[start] != '\0')
		word[index++] = s[start++];
	word[index] = '\0';
	return (word);
}

char	**check_command2(char	*str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '\'')
			return(ft_split_awk(str, '\''));
		else if (str[index] == '"')
			return(ft_split_awk(str, '"'));
		index++;
	}
	return (ft_split_quote(str, ' '));
}

// int	main(int argc, char **argv)
// {
// 	// char	*str = "awk \"'{count++} END {print count}'\"";
// 	// char	*str = "grep a";
// 	// char	*str = "grep 'a'";
// 	char	**result;
// 	// char	*cmd[3] = {"awk", "{count++} END {print count}", 0};
// 	// int 	infile = open("deepthought.txt", O_RDONLY);
// 	// char	*command = "'{count++} END {print count}'";

// 	// command = ft_substr(command, 1, ft_strlen(command) - 2);
	
// 	// printf("%s\n", command);
// 	// dup2(infile, 0);
// 	// execve("/usr/bin/awk", cmd, NULL);
// 	// printf("hallo\n");
// 	if (argc == 2)
// 	{
// 		result = check_command2(argv[1]);
// 		while (*result)
// 		{
// 			printf("%zu, %s\n", ft_strlen(*result), *result);
// 			result++;
// 		}
// 	}
// 	else
// 		printf("%d\n", argc);
// }
