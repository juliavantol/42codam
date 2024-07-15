/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/15 16:20:42 by Julia         #+#    #+#                 */
/*   Updated: 2024/07/15 17:02:18 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	try
	{
		Base *p;
		
		p = generate();
		std::cout << "Object generated" << std::endl;
		std::cout << "Identifying using pointer (p*): ";
		identify(p);
		std::cout << "Identifying using reference (p&): ";
		identify(*p);
		delete p;
	}
	catch (std::exception &error)
	{
		std::cout << "Error" << std::endl;
	}
}