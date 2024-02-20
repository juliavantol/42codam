/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 00:36:50 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/20 13:20:58 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << std::endl << "----- Animal Array Test -----" << std::endl << std::endl;
	const Animal *animals[6] = {new Cat(), new Cat(), new Cat()
							, new Dog(), new Dog(), new Dog()};
	
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
		animals[i]->makeSound();
	
	std::cout << std::endl;
	
	for (int i = 0; i < 6; i++)
		delete animals[i];

	std::cout << std::endl << "----- Subject Test -----" << std::endl << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	delete j;
	delete i;

	return (0);
}
