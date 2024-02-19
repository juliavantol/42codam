/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 00:36:50 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/19 14:27:42 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main(void)
{
	Animal	animal = Animal();
	Dog		dog = Dog();
	Cat		cat = Cat();

	std::cout << std::endl;

	std::cout << "Type: " << animal.getType() << std::endl;
	std::cout << "Type: " << dog.getType() << std::endl;
	std::cout << "Type: " << cat.getType() << std::endl;

	std::cout << std::endl;
	return (0);
}
