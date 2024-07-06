/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 14:08:38 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/03/30 16:24:01 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		std::string	const	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat & operator=(Bureaucrat const &other);
		~Bureaucrat();

		std::string	getName(void) const;
		int			getGrade(void) const;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw() { return "Grade too high"; }
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw() { return "Grade too low"; }
		};
};

#endif