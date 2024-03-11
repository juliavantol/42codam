/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 15:12:02 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/03/11 17:49:18 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructed" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " destructed" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now guarding the gate." << std::endl;	
}

void	ScavTrap::attack(const std::string & target)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy left for attacking." << std::endl;
		return;
	}
	std::cout	<< "ScavTrap " << this->_name << " attacks " << target
				<< ", causing " << this->_attackDamage << " points of damage." << std::endl;
	this->_energyPoints--;
}
