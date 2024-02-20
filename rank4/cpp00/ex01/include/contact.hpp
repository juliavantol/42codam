/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 15:48:09 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/20 14:33:43 by juvan-to      ########   odam.nl         */
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
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phonenumber;
		std::string _darkestsecret;
	
	public:
		Contact();
		~Contact();
		void	new_contact(int index);
		void	view_contact(void) const;
		bool	is_empty(void) const;
};

#endif