/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 00:36:50 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/19 17:51:50 by juvan-to      ########   odam.nl         */
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
	// Create objects of derived classes
    Dog dog;
    Cat cat;

	std::cout << std::endl;

    // Create pointers to objects of the base class type
    Animal* animal1 = &dog;
    Animal* animal2 = &cat;

    // Call the makeSound() function through the pointers
	std::cout << "Type: " << animal1->getType() << std::endl;
    animal1->makeSound();
	std::cout << std::endl << "Type: " << animal2->getType() << std::endl;
    animal2->makeSound();
	
	std::cout << std::endl;
	

	std::cout << "---------- WrongAnimal & WrongCat ----------" << std::endl;
	WrongAnimal* wrongcat = new WrongCat();
	WrongAnimal* wronganimal = new WrongAnimal();
	std::cout << std::endl;

	std::cout << "Type: " << wrongcat ->getType() << std::endl;
	wrongcat->makeSound();
	std::cout << std::endl << "Type: " << wronganimal->getType() << std::endl;
    wronganimal->makeSound();
	
	std::cout << std::endl;
	delete wrongcat;
	delete wronganimal;
	return (0);
}
