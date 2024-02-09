/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 15:48:09 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/09 17:53:03 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class	Contact
{
	private:
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phonenumber;
		std::string _darkestsecret;
	
	public:
		// Default constructor
		Contact() {}
		// Parameterized constructor
		Contact(std::string firstname, std::string lastname,
				std::string nickname, std::string phonenumber,
				std::string darkestsecret);
		~Contact();	
};

#endif