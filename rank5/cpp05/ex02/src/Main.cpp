/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 14:08:43 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/10 13:20:24 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
	std::cout << GREEN << BOLD << "----------------- TEST 1 -----------------" << RESET << std::endl;
	try
	{
		Bureaucrat b1("b1", 60);

	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl << GREEN << BOLD << "----------------- TEST 2 ----------------" << RESET << std::endl;
	try
	{
		

	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	return 0;
}
