/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 14:08:43 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/10 17:38:54 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "Constructing bureaucrat with 0 --> ";
	try
	{
		Bureaucrat	high("A", 0);
		std::cout << high << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught error: " << e.what() << std::endl;
	}
	std::cout << "Constructing bureaucrat with 151 --> ";
	try
	{
		Bureaucrat	low("B", 151);
		std::cout << low << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught error: " << e.what() << std::endl;
	}
	std::cout << "----" << std::endl;
	std::cout << "Constructing bureaucrat with 100 --> ";
	try
	{
		Bureaucrat	bob("Bob", 150);
		
		std::cout << bob << std::endl;

		std::cout << "Incrementing Bob's grade" << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl << std::endl;

		std::cout << "Decrementing Bob's grade" << std::endl;
		bob.decrementGrade();
		std::cout << bob << std::endl << std::endl;

		std::cout << "Decrementing Bob's grade" << std::endl;
		bob.decrementGrade();
		std::cout << bob << std::endl << std::endl;
		std::cout << "----" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught error: " << e.what() << std::endl;
	}
	return 0;
}
