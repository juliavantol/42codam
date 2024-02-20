/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 14:05:01 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/20 13:16:12 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "[Dog] constructor has been called." << std::endl;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "[Dog] destructor has been called." << std::endl;
}

Dog::Dog(const Dog &rhs)
{
	*this = rhs;
	std::cout << "[Dog] copy constructor has been called." << std::endl;
}

Dog & Dog::operator=(const Dog & rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
	}
	std::cout << "[Dog] copy assignment operator has been called." << std::endl;
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}
