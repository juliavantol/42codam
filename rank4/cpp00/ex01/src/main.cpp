/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 15:47:22 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/20 14:34:14 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "contact.hpp"
#include "phonebook.hpp"

void	start_message(void)
{
	std::cout << "*-----------------------------------------------*" << std::endl;
    std::cout << "|                                               |" << std::endl;
    std::cout << "|                   Phonebook                   |" << std::endl;
    std::cout << "|                                               |" << std::endl;
    std::cout << "|             ADD = add new contact             |" << std::endl;
    std::cout << "|             SEARCH = find a contact           |" << std::endl;
    std::cout << "|             EXIT = exit program               |" << std::endl;
    std::cout << "|                                               |" << std::endl;
    std::cout << "*-----------------------------------------------*" << std::endl;
}

int main(void)
{
	PhoneBook	phonebook;
	std::string	input = "";
	
	start_message();
	while (1)
	{
		std::cout << "> " << std::flush;
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0)
			phonebook.add_contact();
		else if (input.compare("SEARCH") == 0)
			phonebook.search_contact();
		else if (input.compare("EXIT") == 0)
			break;
		else
			continue;
	}
}
