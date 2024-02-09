/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 15:47:22 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/09 17:54:14 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "contact.hpp"
#include "phonebook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	Contact		contact;
	std::string	input;
	
	while (1)
	{
		std::cout << "> ";
		std::cin >> input;
		if (input.compare("ADD") == 0)
			std::cout << "adding" << std::endl;
		else if (input.compare("SEARCH") == 0)
			std::cout << "searching" << std::endl;
		else if (input.compare("EXIT") == 0)
			break;
		else
			continue;
	}
}

