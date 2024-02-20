/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 15:47:14 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/20 14:36:49 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"
#include <cstdlib>

class PhoneBook
{
	public:

		PhoneBook();
		~PhoneBook();
		void	add_contact(void);
		void	search_contact(void);
		void	view_all_contacts(void) const;
		
	private:
		Contact _contacts[8];
};

#endif

