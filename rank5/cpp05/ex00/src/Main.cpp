/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 14:08:43 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/03/30 16:24:44 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat	high("B", 0);
		std::cout << high.getName() << ": " << high.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught error: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	low("A", 151);
		std::cout << low.getName() << ": " << low.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
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
