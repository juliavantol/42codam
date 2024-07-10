/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/08 12:57:20 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/09 17:00:07 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string	const	_name;
		bool				_signed;
		int	const			_signGrade;
		int	const			_executeGrade;

	public:
		AForm(const std::string &name, int signGrade, int executeGrade);
		~AForm();
		AForm(AForm const &other);
		AForm &operator=(const AForm &other);

		// Getters
		std::string		getName(void) const;
		bool			getSignStatus(void) const;
		int				getSignGrade(void) const;
		int				getExecuteGrade(void) const;

		virtual void	beSigned(Bureaucrat &bureaucrat) = 0;
		

		// Exceptions
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

std::ostream & operator<<(std::ostream &o, const AForm &rhs);

#endif