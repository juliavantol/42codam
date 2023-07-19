#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int ft_atoi(const char *str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    // Handle whitespace characters
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i++;

    // Handle sign characters
    if (str[i] == '+' || str[i] == '-') {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }

    // Convert digits to integer
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}

char *int_to_hexadecimal(int num, char output[]) {
    int index = 0;

    // Handle 0 as a special case
    if (num == 0) {
        output[index++] = '0';
    }

    // Convert each digit to its corresponding hexadecimal character
    while (num != 0) {
        int remainder = num % 16;

        if (remainder < 10) {
            output[index++] = remainder + '0'; // Convert to character '0' to '9'
        } else {
            output[index++] = remainder - 10 + 'a'; // Convert to character 'A' to 'F'
        }

        num /= 16;
    }

    // Add null terminator at the end of the string
    output[index] = '\0';

    // Reverse the string to get the correct hexadecimal representation
    int start = 0;
    int end = index - 1;
    while (start < end) {
        char temp = output[start];
        output[start] = output[end];
        output[end] = temp;
        start++;
        end--;
    }
	return (output);
}

int main(int argc, char **argv) 
{	
	int number;
	char *output;

	if (argc != 2)
		return (0);
	number = ft_atoi(argv[1]);
	output = malloc(10000);
	output = int_to_hexadecimal(number, output);

    printf("Hexadecimal representation: %s\n", output);
	printf("Real: %x\n", number);

    return 0;
}