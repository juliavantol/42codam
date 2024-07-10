/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/10 13:34:25 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/10 15:48:09 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45)
{
	std::srand(std::time(0));
	this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	*this = other;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	this->_target = other._target;
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	int	result = std::rand() % 2;

	if (this->getSignStatus() == false)
		throw AForm::NotSignedException();

    if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	
	if (result == 0)
		std::cout << "*Bzzzzzzzz* " << _target << " has been robotomized!" << std::endl;
	else
		std::cout << "Robotomy failed for " << _target << std::endl;
}
