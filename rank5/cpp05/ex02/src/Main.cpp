/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 14:08:43 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/10 15:23:32 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << GREEN << BOLD << "----------------- TEST 1 -----------------" << RESET << std::endl;
	try
	{
		Bureaucrat				b1("B1", 60);
		ShrubberyCreationForm	shrubForm("S1");

		b1.executeForm(shrubForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl << GREEN << BOLD << "----------------- TEST 2 ----------------" << RESET << std::endl;
	try
	{
		Bureaucrat				b2("B2", 60);
		ShrubberyCreationForm	shrubForm("S2");

		shrubForm.beSigned(b2);
		b2.executeForm(shrubForm);

	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	return 0;
}
