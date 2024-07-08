/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 14:08:43 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/08 12:04:00 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "Constructing bureaucrat with 1 --> ";
	try
	{
		Bureaucrat	high("A", 0);
		std::cout << high.getName() << ": " << high.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught error: " << e.what() << std::endl;
	}
	std::cout << "Constructing bureaucrat with 151 --> ";
	try
	{
		Bureaucrat	low("B", 151);
		std::cout << low.getName() << ": " << low.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught error: " << e.what() << std::endl;
	}
	std::cout << "Constructing bureaucrat with 100 --> ";
	try
	{
		Bureaucrat	bob("Bob", 100);
		
		std::cout << bob.getName() << ": " << bob.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught error: " << e.what() << std::endl;
	}
	return 0;
}
