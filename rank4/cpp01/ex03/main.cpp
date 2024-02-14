/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/13 13:43:44 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/14 01:28:50 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	{
		Weapon	club = Weapon("club");

		HumanA	bob = HumanA("Bob", club);
		bob.attack();
		club.setType("spiked club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("club");

		HumanB	jim = HumanB("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("spiked club");
		jim.attack();
	}
}