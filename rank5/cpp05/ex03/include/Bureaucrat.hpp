/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 14:08:38 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/10 14:40:51 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

#define LOWEST_GRADE 	150
#define HIGHEST_GRADE 	1
#define GREEN			"\033[32m"
#define BOLD			"\033[1m"
#define RESET			"\033[0m"
#define RED				"\033[31m"

class AForm;

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

		void		incrementGrade(void);
		void		decrementGrade(void);
		void		signForm(AForm &form, bool status);
		void        executeForm(const AForm & AForm) const;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream & operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif