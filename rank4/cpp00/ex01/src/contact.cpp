/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 15:48:04 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/20 14:33:54 by juvan-to      ########   odam.nl         */
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
		if (!input.empty() && std::cin.good())
			valid = true;
		else
			std::cin.clear();
	}
	if (input.length() > 10)
	{
		input[9] = '.';
		input.erase(10);
	}
	return input;
}

void	Contact::new_contact(int index)
{
	this->_firstname = get_input("First name: ");
	this->_lastname = get_input("Last name: ");
	this->_nickname = get_input("Nickname: ");
	this->_phonenumber = get_input("Phone number: ");
	this->_darkestsecret = get_input("Darkest secret: ");
	this->_index = index;
}

void	print_spaces(int len)
{
	for (int i = 0; i < (10 - len); i++)
		std::cout << " ";
}

bool	Contact::is_empty(void) const
{
	if (this->_firstname.empty() || this->_lastname.empty() || this->_nickname.empty())
		return true;
	return false;
}

void	Contact::view_contact(void) const
{
	if (this->is_empty() == true)
		return;
	std::cout << std::endl;
	print_spaces(1);
	std::cout << (this->_index) << "|";
	print_spaces(this->_firstname.length());
	std::cout << this->_firstname << "|";
	print_spaces(this->_lastname.length());
	std::cout << this->_lastname << "|";
	print_spaces(this->_nickname.length());
	std::cout << this->_nickname;
}
