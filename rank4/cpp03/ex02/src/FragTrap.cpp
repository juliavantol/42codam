/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 00:05:48 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/19 00:30:14 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << name << " constructed." << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " destructed." << std::endl;
}

// Copy assignment operator
FragTrap & FragTrap::operator=(const FragTrap & rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
        _hitPoints = rhs._hitPoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
	}
	return *this;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap & rhs)
{
	*this = rhs;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " has no energy left for high fiving." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " gives everyone a high five." << std::endl;
	this->_energyPoints--;
}
