#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to check if a number is a power of two
int isPowerOfTwo(unsigned int n) {
    // If n is 0, it's not a power of two
    if (n == 0)
		return 0;

    // Divide n by 2 until it is no longer divisible by 2
    while (n % 2 == 0)
		n = n / 2;

    // Check if the resulting value is 1
    if (n == 1)
		return 1; // It is a power of two
	else
		return 0; // It is not a power of two
}


// gcc -Wall -Wextra -Werror power_of_two.c -o run && ./run
int main(void)
{
	{
		unsigned int num = 2;

		// Check if the number is a power of two and print the result
		if (isPowerOfTwo(num)) {
			printf("%u is a power of two.\n", num);
		} else {
			printf("%u is not a power of two.\n", num);
		}
	}
	{
		unsigned int num = -2;

		// Check if the number is a power of two and print the result
		if (isPowerOfTwo(num)) {
			printf("%u is a power of two.\n", num);
		} else {
			printf("%u is not a power of two.\n", num);
		}
	}
	{
		unsigned int num = -2147483648;

		// Check if the number is a power of two and print the result
		if (isPowerOfTwo(num)) {
			printf("%u is a power of two.\n", num);
		} else {
			printf("%u is not a power of two.\n", num);
		}
	}

	{
		unsigned int num = 2147483647;

		// Check if the number is a power of two and print the result
		if (isPowerOfTwo(num)) {
			printf("%u is a power of two.\n", num);
		} else {
			printf("%u is not a power of two.\n", num);
		}
	}
	// -2147483648
	// 2147483647
    return 0;
}