/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 14:59:51 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/09 16:15:06 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	return;
	std::cout << "Constructing phonebook" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	return;
	std::cout << "Deconstructing phonebook" << std::endl;
}
