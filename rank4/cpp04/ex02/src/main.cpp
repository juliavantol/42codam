/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 00:36:50 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/20 13:58:38 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << std::endl << "----- Animal Array Test -----" << std::endl << std::endl;
	const AAnimal *animals[6] = {new Cat(), new Cat(), new Cat()
							, new Dog(), new Dog(), new Dog()};
	
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
		animals[i]->makeSound();
	
	std::cout << std::endl;
	
	for (int i = 0; i < 6; i++)
		delete animals[i];

	return (0);
}
