/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 01:31:21 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/19 00:03:54 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap bob = ScavTrap("Bob");
	ClapTrap jim = ClapTrap("Jim");

	std::cout << std::endl;

	bob.attack("Jim");
	
	std::cout << std::endl;

	jim.takeDamage(20);
	
	std::cout << std::endl;

	bob.guardGate();

	std::cout << std::endl;
	return 0;
}
