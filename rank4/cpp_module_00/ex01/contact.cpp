/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 15:48:04 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/09 17:53:16 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "contact.hpp"

Contact::Contact(std::string p1, std::string p2, std::string p3,
	std::string p4, std::string p5) : _firstname(p1), _lastname(p2), _nickname(p3)
									, _phonenumber(p4), _darkestsecret(p5)
{
	return;
	std::cout << "Constructing Contact" << std::endl;
}

Contact::~Contact(void)
{
	return;
	std::cout << "Deconstructing Contact" << std::endl;
}

