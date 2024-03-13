/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main2.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 00:36:50 by Julia         #+#    #+#                 */
/*   Updated: 2024/03/13 17:57:57 by juvan-to      ########   odam.nl         */
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
	std::cout << "---------- Constructors ----------" << std::endl;
	// Create objects of derived classes
    Dog dog;
    Cat cat;
	std::cout << std::endl;
    
	// Create pointers to objects of the base class type
    Animal* animal1 = &dog;
    Animal* animal2 = &cat;

	std::cout << "--------------- Dog & Cat -----------------" << std::endl;
    // Call the makeSound() function through the pointers
	std::cout << animal1->getType() << ": ";
    animal1->makeSound();
	std::cout << animal2->getType() << ": ";
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
	std::cout << "---------- Destructors ----------" << std::endl;
	
	delete wrongcat;
	delete wronganimal;
	return (0);
}
