/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 14:07:10 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/19 15:12:29 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Cat constructor" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor" << std::endl;
}

Cat::Cat(const Cat &rhs)
{
	*this = rhs;
	std::cout << "Cat copy constructor" << std::endl;
}

Cat & Cat::operator=(const Cat & rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
	}
	std::cout << "Cat copy assignment operator" << std::endl;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}
