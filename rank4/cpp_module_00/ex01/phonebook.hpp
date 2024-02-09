/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 15:47:14 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/09 17:52:32 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
	public:
		Contact contacts[8];

		PhoneBook();
		~PhoneBook();
		
	private:
		// stuff
};

#endif

