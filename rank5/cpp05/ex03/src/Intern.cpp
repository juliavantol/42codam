/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/10 16:20:22 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/10 17:32:53 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::~Intern(void)
{
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern & Intern::operator=(const Intern &other)
{
	(void) other;
	return *this;
}

const char* Intern::Exception::what() const throw()
{
	return "Form not found";
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string formNames[] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
    };
	AForm		*forms[] = {
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target),
		new ShrubberyCreationForm(target)
    };
	AForm	*form = nullptr;
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		if (formNames[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			form = forms[i];
			break;
		}
	}
	for (int j = 0; j < 3; j++)
	{
		if (i != j)
			delete forms[j];
	}
	if (form == nullptr)
		throw Intern::Exception();
	return form;
}
