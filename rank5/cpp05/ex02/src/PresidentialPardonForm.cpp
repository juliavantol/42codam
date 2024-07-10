/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/10 13:34:28 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/10 15:58:05 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	*this = other;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	this->_target = other._target;
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getSignStatus() == false)
	{
		std::cout << "Couldn't execute form: ";
		throw AForm::NotSignedException();
	}
    else if (executor.getGrade() > this->getExecuteGrade())
	{
		std::cout << "Couldn't execute form: ";
		throw AForm::GradeTooLowException();
	}
	
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
