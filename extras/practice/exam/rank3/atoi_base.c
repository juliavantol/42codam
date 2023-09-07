#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int atoi_base(const char* str, int base) {
    int result = 0;
    int sign = 1;
    int i = 0;

    // Check for negative sign
    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    // Convert string to integer
    while (str[i] != '\0') {
        char c = tolower(str[i]);

        // Convert digit characters to their corresponding values
        if (isdigit(c))
            result = result * base + (c - '0');
        else if (isalpha(c))
            result = result * base + (c - 'a' + 10);

        i++;
    }

    return result * sign;
}

int main() {
    char str[] = "1345"; // Example hexadecimal string
    int base = 12; // Base 16 for hexadecimal

    int value = atoi_base(str, base);

    printf("Converted value: %d\n", value);
	printf("atoi: %d\n", atoi("s123s"));

    return 0;
}
