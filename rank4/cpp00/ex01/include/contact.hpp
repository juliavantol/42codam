/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 15:48:09 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/21 16:25:25 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string.h>

class	Contact
{
	private:
		int			_index;
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
	
	public:
		Contact();
		~Contact();
		void		newContact(int index);
		void		viewContact(void) const;
		void		displayAllFields(void) const;
		void		printAndTruncate(std::string field) const;
		bool		isEmpty(void) const;
};

#endif