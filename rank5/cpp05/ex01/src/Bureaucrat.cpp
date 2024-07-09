/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 14:08:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/09 17:32:42 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Random"), _grade(150) 
{
	return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) 
{
	if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	return;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {	
}

// Copy assignment operator
Bureaucrat & Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
	{
		// Only non-const members can be assigned
		this->_grade = other.getGrade();
	}
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat(void) {
}

// 1 (highest possible grade) so for incrementing subtract 1
void	Bureaucrat::incrementGrade(void)
{
	if (this->getGrade() - 1 < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

// 150 (lowest possible grade) so for decrementing add 1
void	Bureaucrat::decrementGrade(void)
{
	if (this->getGrade() + 1 > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

std::string	Bureaucrat::getName(void) const
{
	return this->_name;
}

int	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void	Bureaucrat::signForm(Form &form, bool status)
{
	if (status == true)
		std::cout << GREEN << this->getName() << " signed " << form.getName() << RESET << std::endl;
	else
		std::cout << this->getName() << " couldn't sign " << form.getName()
					<< " because: ";
}

// Overload of the insertion operator
std::ostream& operator<<(std::ostream &o, const Bureaucrat &rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
