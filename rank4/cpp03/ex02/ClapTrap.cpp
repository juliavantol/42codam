/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 13:27:57 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/19 00:02:15 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " constructed." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " destructed." << std::endl;
}

// Copy assignment operator
ClapTrap & ClapTrap::operator=(const ClapTrap & rhs)
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
ClapTrap::ClapTrap(const ClapTrap & rhs)
{
	*this = rhs;
}

void	ClapTrap::attack(const std::string & target)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
	{
		std::cout << this->_name << " has no energy left for attacking." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= int(amount))
	{
		this->_hitPoints = 0;
		std::cout << this->_name << " is dead." << std::endl;
		return;
	}
	std::cout << this->_name << " takes " << amount << " points of damage." << std::endl;
	this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead." << std::endl;
		return;
	}
	if ((this->_hitPoints + amount) >= 10)
	{
		this->_hitPoints = 10;
		std::cout << this->_name << " is now back to full health." << std::endl;
	}
	else
	{
		std::cout << this->_name << " repairs themselves with " << amount << " points." << std::endl;
		this->_hitPoints += amount;
	}
	this->_energyPoints --;
}
