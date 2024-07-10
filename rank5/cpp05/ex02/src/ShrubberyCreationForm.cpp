/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/10 13:34:20 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/10 15:22:43 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	*this = other;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	this->_target = other._target;
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (this->getSignStatus() == false)
		throw AForm::NotSignedException();

	// Check if executor has the required grade to execute the form
    if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();

	std::string		filename = this->_target + "_shrubbery";
	std::ofstream	outputFile;
	
	outputFile.open (filename);
	std::string tree =
	"                                             .         ;	\n"
	"            .              .              ;%     ;;		\n"
	"              ,           ,                :;%  %;			\n"  
	"               :         ;                   :;%;'			\n"
	"      ,.        %;     %;            ;        %;'    ,;	\n"
	"        ;       ;%;  %%;        ,     %;    ;%;    ,%'		\n"
	"         %;       %;%;      ,  ;       %;  ;%;   ,%;'		\n"
	"          ;%;      %;        ;%;        % ;%;  ,%;'		\n"
	"           `%;.     ;%;     %;'         `;%%;.%;'			\n"
	"            `:;%.    ;%%. %@;        %; ;@%;%'				\n"
	"               `:%;.  :;bd%;          %;@%;'				\n"
	"                 `@%:.  :;%.         ;@@%;'				\n"
	"                   `@%.  `;@%.      ;@@%;					\n"
	"                     `@%%. `@%%    ;@@%;					\n"
	"                       ;@%. :@%%  %@@%;					\n"
	"                         %@bd%%%bd%%:;						\n"
	"                           #@%%%%%:;;						\n"
	"                           %@@%%%::;						\n"
	"                           %@@@%(o);  .'					\n"
	"                           %@@@o%;:(.,'					\n"
	"                       `.. %@@@o%::;						\n"
	"                          `)@@@o%::;						\n"
	"                           %@@(o)::;						\n"
	"                          .%@@@@%::;						\n"
	"                          ;%@@@@%::;.						\n"
	"                         ;%@@@@%%:;;;.						\n"
	"                     ...;%@@@@@%%:;;;;,..					\n";
						
	outputFile << tree;
	outputFile.close();
}
