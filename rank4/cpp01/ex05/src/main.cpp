/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 01:31:21 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/27 22:49:05 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(void)
{
	Harl	customer;

	customer.complain("DEBUG");
	std::cout << std::endl;
	customer.complain("INFO");
	std::cout << std::endl;
	customer.complain("WARNING");
	std::cout << std::endl;
	customer.complain("ERROR");
	std::cout << std::endl;
	customer.complain("UNKNOWN");
	return 0;
}
