/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 14:07:10 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/03/14 12:35:22 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "[Cat] constructed." << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "[Cat] destructed." << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}
