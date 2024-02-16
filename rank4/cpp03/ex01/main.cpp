/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 01:31:21 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/16 14:54:18 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap jim = ClapTrap("Jim");
	ClapTrap bob = ClapTrap("Bob");

	std::cout << std::endl;

	jim.attack("Bob");
	bob.takeDamage(3);
	bob.takeDamage(3);
	bob.takeDamage(3);
	std::cout << std::endl;
	
	bob.beRepaired(9);
	std::cout << std::endl;

	jim.attack("Bob");
	bob.takeDamage(5);
	std::cout << std::endl;

	jim.attack("Bob");
	bob.takeDamage(7);

	std::cout << std::endl;
	return 0;
}
