/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 17:46:04 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/08 00:25:35 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// 1. `Divide the original decimal number by 16`
// 2. `Divide the quotient by 16`
// 3. `Repeat the step 2 until we get quotient equal to zero`

// 1 Store the remainder when the number is divided by 16 in a 
// temporary variable temp. If temp is less than 10, 
// insert (48 + temp) in a character array otherwise if temp is 
// greater than or equals to 10, insert (55 + temp) in the character array.
// 2 Divide the number by 16 now
// 3 Repeat the above two steps until the number is not equal to 0.
// 4 Print the array in reverse order now.

int	main(void)
{
	char	*a;

	a = "hello!";
	printf("\n%d\n", printf("word: %s", a));
	printf("\n%d\n", ft_printf("word: %s word: %s", a, a));
	return (0);
}
