/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 14:07:10 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/20 13:16:32 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "[Cat] constructor has been called." << std::endl;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "[Cat] destructor has been called." << std::endl;
}

Cat::Cat(const Cat &rhs)
{
	*this = rhs;
	std::cout << "[Cat] copy constructor has been called." << std::endl;
}

Cat & Cat::operator=(const Cat & rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
	}
	std::cout << "[Cat] copy assignment operator has been called." << std::endl;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}
