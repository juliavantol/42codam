/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 16:58:09 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/19 17:40:28 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal constructor has been called." << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor has been called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs)
{
	*this = rhs;
	std::cout << "WrongAnimal copy constructor has been called." << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
	}
	std::cout << "WrongAnimal copy assignment operator has been called." << std::endl;
	return *this;
}

std::string	WrongAnimal::getType(void)
{
	return this->type;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "makeSound() for [WrongAnimal] was called." << std::endl;
}
