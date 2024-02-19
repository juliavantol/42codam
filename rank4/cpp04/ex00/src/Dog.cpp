/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 14:05:01 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/19 15:12:25 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "Dog constructor" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor" << std::endl;
}

Dog::Dog(const Dog &rhs)
{
	*this = rhs;
	std::cout << "Dog copy constructor" << std::endl;
}

Dog & Dog::operator=(const Dog & rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
	}
	std::cout << "Dog copy assignment operator" << std::endl;
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}
