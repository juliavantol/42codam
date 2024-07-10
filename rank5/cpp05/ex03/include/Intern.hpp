/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/10 16:20:24 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/10 16:24:11 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern & operator=(const Intern &other);
		~Intern();
};

#endif