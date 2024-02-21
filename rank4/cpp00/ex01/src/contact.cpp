/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 15:48:04 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/21 16:18:01 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

std::string	get_input(std::string prompt)
{
	std::string	input = "";
	bool		valid = false;

	while (!valid)
	{
		std::cout << prompt << std::flush;
		std::getline(std::cin, input);
		if (!input.empty() && std::cin.good()
			&& input.find_first_not_of("	 ") != std::string::npos)
			valid = true;
		else
			std::cin.clear();
	}
	return input;
}

void	Contact::newContact(int index)
{
	this->_firstName = get_input("First name: ");
	this->_lastName = get_input("Last name: ");
	this->_nickname = get_input("Nickname: ");
	this->_phoneNumber = get_input("Phone number: ");
	this->_darkestSecret = get_input("Darkest secret: ");
	this->_index = index;
}

bool	Contact::isEmpty(void) const
{
	if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
		return true;
	return false;
}

void	Contact::printAndTruncate(std::string field) const
{
	std::string	output;
	
	if (field.length() > 10)
		output = field.substr(0, 9) + ".";
	else
		output = field;
	int spaces = 10 - output.length();
	std::cout << std::string(spaces, ' ') << output;
}

void	Contact::viewContact(void) const
{
	if (this->isEmpty() == true)
		return;
	std::cout << std::endl << "         " << (this->_index) << "|";
	this->printAndTruncate(this->_firstName);
	std::cout << "|";
	this->printAndTruncate(this->_lastName);
	std::cout << "|";
	this->printAndTruncate(this->_nickname);
}

void	Contact::displayAllFields(void) const
{
	if (this->isEmpty() == true)
		return;
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
}
