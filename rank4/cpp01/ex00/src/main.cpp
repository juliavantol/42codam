/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/13 12:03:42 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/13 12:39:25 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	Zombie	*heap_zombie = newZombie("HeapZombie");
	heap_zombie->announce();

	randomChump("StackZombie");

	delete heap_zombie;
	return 0;
}
