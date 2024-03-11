/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 01:31:21 by Julia         #+#    #+#                 */
/*   Updated: 2024/03/11 13:47:35 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(7);
	Fixed c(3.50f);

	std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;
	std::cout << "------------Comparison Operators Test-------------" << std::endl;
	std::cout << a << " == " << b << ": " << (a == b) << std::endl;
	std::cout << a << " != " << b << ": " << (a != b) << std::endl;
	std::cout << b << " > " << c << ": " << (b > c) << std::endl;
	std::cout << b << " < " << c << ": " << (b < c) << std::endl;
	std::cout << b << " >= " << c << ": " << (b >= c) << std::endl;
	std::cout << b << " <= " << c << ": " << (b <= c) << std::endl;

	std::cout << std::endl << "------------Arithmetic Operators Test-------------" << std::endl;
	Fixed result = b + c;
	std::cout << b << " + " << c << " = " << result << std::endl;
	result = b - c;
	std::cout << b << " - " << c << " = " << result << std::endl;
	result = b * c;
	std::cout << b << " * " << c << " = " << result << std::endl;
	result = b / c;
	std::cout << b << " / " << c << " = " << result << std::endl;

	std::cout << std::endl << "------Increment and Decrement Operators Test------" << std::endl;
	Fixed d;
    std::cout << "Start: " << d << std::endl;
    std::cout << "Pre-increment: " << ++d << std::endl;
    std::cout << "After pre-increment: " << d << std::endl;
    std::cout << "Post-increment: " << d++ << std::endl;
    std::cout << "After post-increment: " << d << std::endl;
	
	std::cout << std::endl << "Pre-decrement: " << --d << std::endl;
    std::cout << "After pre-decrement: " << d << std::endl;
    std::cout << "Post-decrement: " << d-- << std::endl;
    std::cout << "After post-decrement: " << d << std::endl;

	std::cout << std::endl << "--------------Min/max Operators Test--------------" << std::endl;
	Fixed x = Fixed::min(b, c);
	std::cout << "Min of " << b << " and " << c << ": " << x << std::endl;
	x = Fixed::max(b, c);
	std::cout << "Max of " << b << " and " << c << ": " << x << std::endl;

	return 0;
}
