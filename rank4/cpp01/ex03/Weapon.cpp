/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/13 13:43:12 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/13 13:48:54 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	std::cout << "Constructing weapon" << std::endl;
	return;
}

Weapon::~Weapon(void)
{
	std::cout << "Deconstructing weapon" << std::endl;
	return;
}

std::string	Weapon::getType(void) const
{
	return this->_weapon;
}

void	Weapon::setType(std::string type)
{
	this->_weapon = type;
}