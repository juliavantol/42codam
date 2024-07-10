/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/08 12:57:16 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/09 17:29:31 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string &name, int signGrade, int executeGrade) : _name(name), _signed(false)
									, _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < HIGHEST_GRADE || executeGrade < HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	else if (signGrade > LOWEST_GRADE || executeGrade > LOWEST_GRADE)
		throw AForm::GradeTooLowException();
}

AForm::AForm(void) : _name("Default"), _signed(false), _signGrade(60), _executeGrade(60)
{
	return;
}

AForm::~AForm(void)
{
}

// Copy constructor
AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed)
							, _signGrade(other._signGrade), _executeGrade(other._executeGrade) {
}

// Copy assignment operator
AForm & AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		// Only non-const members can be assigned
		this->_signed = other.getSignStatus();
	}
	return *this;
}

// Getters
std::string	AForm::getName(void) const
{
	return _name;
}

bool	AForm::getSignStatus(void) const
{
	return _signed;
}

int		AForm::getSignGrade(void) const
{
	return _signGrade;
}

int		AForm::getExecuteGrade(void) const
{
	return _executeGrade;
}

// Sets the AForm status to signed if the bureaucrat’s grade is high enough
void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade())
	{
		this->_signed = true;
		bureaucrat.signForm(*this, true);
	}
	else
	{
		this->_signed = false;
		bureaucrat.signForm(*this, false);
		throw AForm::GradeTooLowException();
	}
}

// Exceptions
const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char*	AForm::NotSignedException::what() const throw()
{
	return "Form is not signed";
}

// Overloading of the insertion operator
std::ostream& operator<<(std::ostream &o, const AForm &rhs)
{
	o << "AForm name:		" << rhs.getName() << std::endl
		<< "Sign status:		" << rhs.getSignStatus()
		<< std::endl << "Grade to sign:		" << rhs.getSignGrade()
		<< std::endl << "Grade to execute:	" << rhs.getExecuteGrade();
	return o;
}
