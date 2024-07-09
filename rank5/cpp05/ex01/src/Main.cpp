/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 14:08:43 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/09 17:20:06 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << GREEN << BOLD << "----------------- TEST 1 -----------------" << RESET << std::endl;
	try
	{
		// To get the form to signed b1 should be lower than the form
		Bureaucrat b1("B1", 20);
		Form f1("Test1", 60, 60);
		std::cout << b1 << std::endl << std::endl;
		std::cout << f1 << std::endl << std::endl;

		f1.beSigned(b1);
		std::cout << std::endl;
		std::cout << f1 << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl << GREEN << BOLD << "----------------- TEST 2 ----------------" << RESET << std::endl;
	try
	{
		// Grade too low
		Bureaucrat b1("B1", 20);
		Form f1("Test1", 10, 10);
		std::cout << b1 << std::endl << std::endl;
		std::cout << f1 << std::endl << std::endl;

		f1.beSigned(b1);
		std::cout << std::endl;
		std::cout << f1 << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	return 0;
}
