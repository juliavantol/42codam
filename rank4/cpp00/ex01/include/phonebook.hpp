/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 15:47:14 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/21 14:26:50 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"
#include <cstdlib>

class PhoneBook
{
	private:
		Contact _contacts[8];

	public:

		PhoneBook();
		~PhoneBook();
		void	addContact(void);
		void	searchContact(void);
		void	viewAllContacts(void) const;
		bool	isEmpty(void) const;
};

#endif

