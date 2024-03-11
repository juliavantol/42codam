/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 01:31:21 by Julia         #+#    #+#                 */
/*   Updated: 2024/03/11 17:56:43 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "----------Construction-----------" << std::endl;
	ScavTrap bob = ScavTrap("Bob");
	std::cout << std::endl;

	ScavTrap billy = ScavTrap("Billy");
	std::cout << std::endl;

	ClapTrap jim = ClapTrap("Jim");
	std::cout << "---------------------------------" << std::endl;
	std::cout << std::endl;

	jim.attack("Bob");
	std::cout << std::endl;
	
	bob.guardGate();
	std::cout << std::endl;
	
	bob.attack("Jim");
	jim.takeDamage(20);
	std::cout << std::endl;
	
	bob.attack("Billy");
	billy.takeDamage(20);
	bob.attack("Billy");
	billy.takeDamage(20);
	bob.attack("Billy");
	billy.takeDamage(20);
	bob.attack("Billy");
	billy.takeDamage(20);
	bob.attack("Billy");
	billy.takeDamage(20);

	std::cout << std::endl;
	std::cout << "-----------Destruction----------" << std::endl;
	return 0;
}
