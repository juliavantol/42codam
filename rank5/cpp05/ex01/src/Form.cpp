/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/08 12:57:16 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/08 14:28:48 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int signGrade, int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	
}

Form::~Form(void)
{
	
}

// Getters
std::string	Form::getName(void) const
{
	return _name;
}

bool	Form::getSignStatus(void) const
{
	return _signed;
}

int		Form::getSignGrade(void) const
{
	return _signGrade;
}

int		Form::getExecuteGrade(void) const
{
	return _executeGrade;
}

// Exceptions
const char*	Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

// Overloading of the insertion operator
std::ostream& operator<<(std::ostream &o, const Form &rhs)
{
	o << "Name: " << rhs.getName() << std::endl << "Sign status: " << rhs.getSignStatus() <<
	std::endl << "Sign grade: " << rhs.getSignGrade() << std::endl << "Execute grade: " << rhs.getExecuteGrade();
	return o;
}
