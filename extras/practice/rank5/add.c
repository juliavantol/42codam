#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // Maximum size of the array to store digits

// Function to add two numbers represented as strings
char* add(char *num1, char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxSize = len1 > len2 ? len1 + 2 : len2 + 2; // Extra space for possible carry and null terminator
    int result[MAX_SIZE];
    int carry = 0;
    int i = len1 - 1, j = len2 - 1, k = 0;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = i >= 0 ? num1[i--] - '0' : 0;
        int digit2 = j >= 0 ? num2[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result[k++] = sum % 10;
        carry = sum / 10;
    }

    char *output = (char*)malloc(k + 1); // +1 for null terminator
    if (output == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }

    for (i = k - 1, j = 0; i >= 0; i--, j++)
        output[j] = result[i] + '0';
    output[j] = '\0';
	maxSize--;
    return output;
}

int main() {
    char num1[MAX_SIZE], num2[MAX_SIZE];

    printf("Enter the first number: ");
    scanf("%s", num1);
    printf("Enter the second number: ");
    scanf("%s", num2);

    // Check if the numbers are negative
    int isNegative1 = (num1[0] == '-');
    int isNegative2 = (num2[0] == '-');

    char *result;
    // Case 1: Both numbers are negative
    if (isNegative1 && isNegative2) {
        result = add(num1 + 1, num2 + 1);
        printf("Result: -%s\n", result);
    }
    // Case 2: First number is negative, second number is positive
    else if (isNegative1 && !isNegative2) {
        result = add(num1 + 1, num2);
        printf("Result: %s\n", result);
    }
    // Case 3: First number is positive, second number is negative
    else if (!isNegative1 && isNegative2) {
        result = add(num1, num2 + 1);
        printf("Result: %s\n", result);
    }
    // Case 4: Both numbers are positive
    else {
        result = add(num1, num2);
        printf("Result: %s\n", result);
    }

    free(result); // Free dynamically allocated memory
    return 0;
}
