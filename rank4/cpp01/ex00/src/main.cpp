/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/13 12:03:42 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/26 14:24:40 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	// Heap allocated zombie
	Zombie	*heap_zombie = newZombie("HeapZombie");
	heap_zombie->announce();
	
	// Stack allocated zombie
	randomChump("StackZombie");

	// Deallocate heap allocated zombie
	if (heap_zombie)
		delete heap_zombie;
	return 0;
}
