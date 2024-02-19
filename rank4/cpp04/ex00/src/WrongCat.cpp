/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 17:26:54 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/19 17:36:42 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor has been called." << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor has been called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &rhs)
{
	*this = rhs;
	std::cout << "WrongCat copy constructor has been called." << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat & rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
	}
	std::cout << "WrongCat copy assignment operator has been called." << std::endl;
	return *this;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "makeSound() for [WrongCat] was called." << std::endl;
}
