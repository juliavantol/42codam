
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

void	trim_leading_zeros(char **str) {
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

char	*subtract(char *s1, char *s2)
{
	int len1 = ft_strlen(s1);
	int len2 = ft_strlen(s2);
	int max_len = (len1 > len2) ? len1 : len2;
	int output_len = max_len;
	char *output = malloc((output_len + 1) * sizeof(char));
	if (!output)
		return (NULL);

	int borrow = 0;
	for (int i = 0; i < output_len; i++)
		output[i] = '0';
	output[output_len] = '\0';

	for (int i = 0; i < max_len; i++)
	{
		int diff = borrow;
		if (len1 - 1 - i >= 0)
			diff += s1[len1 - 1 - i] - '0';
		if (len2 - 1 - i >= 0)
			diff -= s2[len2 - 1 - i] - '0';
		if (diff < 0) {
			diff += 10;
			borrow = 1;
		} else {
			borrow = 0;
		}
		output[output_len - 1 - i] = diff + '0';
	}

	trim_leading_zeros(&output);
	return (output);
}

char	*add(char *s1, char *s2)
{
	int len1 = ft_strlen(s1);
	int len2 = ft_strlen(s2);
	int max_len = (len1 > len2) ? len1 : len2;
	int output_len = max_len + 1;
	char *output = malloc((output_len + 1) * sizeof(char));
	if (!output)
		return (NULL);

	int carry = 0;
	for (int i = 0; i < output_len; i++)
		output[i] = '0';
	output[output_len] = '\0';

	for (int i = 0; i < max_len; i++)
	{
		int sum = carry;
		if (len1 - 1 - i >= 0)
			sum += s1[len1 - 1 - i] - '0';
		if (len2 - 1 - i >= 0)
			sum += s2[len2 - 1 - i] - '0';
		carry = sum / 10;
		output[output_len - 1 - i] = (sum % 10) + '0';
	}

	if (carry > 0)
		output[0] = carry + '0';

	trim_leading_zeros(&output);
	return (output);
}

int main(int argc, char **argv) {
	char *output;

	if (argc != 3)
		return 0;

	char *s1 = argv[1];
	char *s2 = argv[2];

	int negative1 = (s1[0] == '-');
	int negative2 = (s2[0] == '-');

	if (negative1 && negative2) {
		// Both numbers are negative, remove '-' sign and add
		output = add(s1 + 1, s2 + 1);
		print_str("-");
	} else if (negative1 && !negative2) {
		// First number is negative, remove '-' sign and subtract
		output = subtract(s1 + 1, s2);
	} else if (!negative1 && negative2) {
		// Second number is negative, remove '-' sign and subtract
		output = subtract(s1, s2 + 1);
	} else {
		// Both numbers are positive, perform addition
		output = add(s1, s2);
	}

	print_str(output);
	print_str("\n");

	return 0;
}