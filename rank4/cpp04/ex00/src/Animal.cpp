/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 13:12:13 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/19 15:10:59 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	this->type = "Default";
	std::cout << "Animal constructor" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor" << std::endl;
}

Animal::Animal(const Animal &rhs)
{
	*this = rhs;
	std::cout << "Animal copy constructor" << std::endl;
}

Animal & Animal::operator=(const Animal & rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
	}
	std::cout << "Animal copy assignment operator" << std::endl;
	return *this;
}

std::string	Animal::getType(void)
{
	return this->type;
}

void	Animal::makeSound(void) const
{
	std::cout << "Silence..." << std::endl;
}
