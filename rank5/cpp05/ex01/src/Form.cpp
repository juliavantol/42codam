/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/08 12:57:16 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/09 17:21:43 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int signGrade, int executeGrade) : _name(name), _signed(false)
									, _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < HIGHEST_GRADE || executeGrade < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	else if (signGrade > LOWEST_GRADE || executeGrade > LOWEST_GRADE)
		throw Form::GradeTooLowException();
}

Form::~Form(void)
{
	
}

// Copy constructor
Form::Form(const Form &other) : _name(other._name), _signed(other._signed)
							, _signGrade(other._signGrade), _executeGrade(other._executeGrade) {
}

// Copy assignment operator
Form & Form::operator=(const Form &other)
{
	if (this != &other)
	{
		// Only non-const members can be assigned
		this->_signed = other.getSignStatus();
	}
	return *this;
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

// Sets the form status to signed if the bureaucrat’s grade is high enough
void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade())
	{
		this->_signed = true;
		bureaucrat.signForm(*this);
	}
	else
	{
		this->_signed = false;
		throw Form::GradeTooLowException();
	}
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
	o << "Form name:	" << rhs.getName() << std::endl << "Sign status:	" << rhs.getSignStatus() <<
	std::endl << "Sign grade:	" << rhs.getSignGrade() << std::endl << "Execute grade:	" << rhs.getExecuteGrade();
	return o;
}
