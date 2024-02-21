/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 14:59:51 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/21 16:17:26 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void	PhoneBook::addContact(void)
{
	static int	index;
	index = index % 8;
	this->_contacts[index].newContact(index);
	std::cout << "--------------" << std::endl;
	std::cout << "Contact added!" << std::endl;
	index++;
}

void	PhoneBook::searchContact(void)
{
	int			index = -1;
	std::string	input = "";

	this->viewAllContacts();
	if (this->isEmpty())
		return ;
	while (1)
	{
		std::cout << "Enter contact ID: " << std::flush;
		std::getline(std::cin, input);
		if (!input.empty() && input.find_first_not_of(' ') != std::string::npos)
			break;
		
	}
	index = std::atoi(input.c_str());
	if (index < 0 || index > 7 || input.find_first_not_of("0123456789") != std::string::npos
		|| this->_contacts[index].isEmpty())
	{
		std::cout << "Invalid ID" << std::endl;
		return;
	}
	this->_contacts[index].displayAllFields();
}

void	PhoneBook::viewAllContacts(void) const
{
	if (this->isEmpty())
	{
		std::cout << "There are currently no contacts in the phonebook." << std::endl;
		return;
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "        ID|First name| Last name|  Nickname" << std::endl;
	std::cout << "-------------------------------------------";
	for (int i = 0; i < 8; i++)
		this->_contacts[i].viewContact();
	std::cout << std::endl << "-------------------------------------------" << std::endl;

}

bool	PhoneBook::isEmpty(void) const
{
	return this->_contacts[0].isEmpty();
}
