#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int		ft_strlen(char *str) {
	int len = 0;
	while (str[len])
		len++;
	return (len);
}

void	print_str(char *str) {
	write(1, str, ft_strlen(str));
}

void	trim_leading_zeros(char **str)
{
	int i = 0;

	while ((*str)[i] == '0' && (*str)[i + 1] != '\0')
	{
		i++;
	}
	if (i > 0) {
		char *new_str = &((*str)[i]);
		*str = new_str;
	}
}

char	*multiply(char *s1, char *s2)
{
	int len1 = ft_strlen(s1);
	int len2 = ft_strlen(s2);
	int output_len = len1 + len2;
	char *output = malloc((output_len + 1) * sizeof(char));
	if (!output)
		return (NULL);

	for (int i = 0; i < output_len; i++)
		output[i] = '0';
	output[output_len] = '\0';

	for (int i = len1 - 1; i >= 0; i--)
	{
		for (int j = len2 - 1; j >= 0; j--)
		{
			int multi = (s1[i] - '0') * (s2[j] - '0') + (output[i + j + 1] - '0');
			output[i + j + 1] = (multi % 10) + '0';
			output[i + j] += multi / 10;
		}
	}

	trim_leading_zeros(&output);
	return (output);
}


int main(int argc, char **argv) {
	char *output;
	int negative = 0;

	if (argc != 3)
		return 0;
	
	char *s1 = argv[1];
	char *s2 = argv[2];
	if (s1[0] == '-')
	{
		negative++;
		s1++;
	}
	if (s2[0] == '-')
	{
		negative++;
		s2++;
	}
	output = multiply(s1, s2);
	if (negative == 1)
		print_str("-");
	print_str(output);
	print_str("\n");
}