/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 13:12:13 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/20 13:16:48 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	this->type = "Default";
	std::cout << "[AAnimal] constructor has been called." << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "[AAnimal] destructor has been called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &rhs)
{
	*this = rhs;
	std::cout << "[AAnimal] copy constructor has been called." << std::endl;
}

AAnimal & AAnimal::operator=(const AAnimal & rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
	}
	std::cout << "[AAnimal] copy assignment operator has been called." << std::endl;
	return *this;
}

std::string	AAnimal::getType(void)
{
	return this->type;
}

void	AAnimal::makeSound(void) const
{
	std::cout << "makeSound() for [AAnimal] was called." << std::endl;
}
