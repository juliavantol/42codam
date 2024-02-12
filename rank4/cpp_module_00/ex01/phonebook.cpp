/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 14:59:51 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/12 17:45:18 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "phonebook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook(void)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void	PhoneBook::add_contact(void)
{
	static int	index;
	index = index % 8;
	this->_contacts[index].new_contact(index);
	index++;
}

void	PhoneBook::search_contact(void)
{
	int			index = -1;
	std::string	input = "";

	this->view_all_contacts();
	while (1)
	{
		std::cout << "Enter contact ID: " << std::flush;
		std::getline(std::cin, input);
		if (!input.empty() && input.find_first_not_of(' ') != std::string::npos)
			break;
		
	}
	index = atoi(input.c_str());
	if (index < 0 || index > 7 || input.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "Invalid ID" << std::endl;
		return;
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "        ID|First name| Last name|  Nickname" << std::endl;
	std::cout << "-------------------------------------------";
	this->_contacts[index].view_contact();
	std::cout << std::endl << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::view_all_contacts(void) const
{
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "        ID|First name| Last name|  Nickname" << std::endl;
	std::cout << "-------------------------------------------";
	for (int i = 0; i < 8; i++)
		this->_contacts[i].view_contact();
	std::cout << std::endl << "-------------------------------------------" << std::endl;

}