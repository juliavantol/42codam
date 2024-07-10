/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 14:08:43 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/10 17:30:23 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout << GREEN << BOLD << "----------------- TEST 1 -----------------" << RESET << std::endl;
	try
	{
		Bureaucrat	b1("B1", 20);
		Intern		someRandomIntern;
		AForm		*rrf;
	
		rrf = someRandomIntern.makeForm("robotomy request", "robot");
		rrf->beSigned(b1);
		b1.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl << GREEN << BOLD << "----------------- TEST 2 ----------------" << RESET << std::endl;
	try
	{
		Bureaucrat	b1("B1", 1);
		Intern		someRandomIntern;
		AForm		*rrf;
	
		rrf = someRandomIntern.makeForm("presidential pardon", "president");
		rrf->beSigned(b1);
		b1.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl << GREEN << BOLD << "----------------- TEST 3 ----------------" << RESET << std::endl;
	try
	{
		Bureaucrat	b1("B1", 10);
		Intern		someRandomIntern;
		AForm		*rrf;
	
		rrf = someRandomIntern.makeForm("shrubbery creation", "shrub");
		rrf->beSigned(b1);
		b1.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl << GREEN << BOLD << "----------------- TEST 4 ----------------" << RESET << std::endl;
	try
	{
		Bureaucrat	b1("B1", 10);
		Intern		someRandomIntern;
		AForm		*rrf;
	
		rrf = someRandomIntern.makeForm("unknown form", "bender");
		rrf->beSigned(b1);
		b1.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return 0;
}
