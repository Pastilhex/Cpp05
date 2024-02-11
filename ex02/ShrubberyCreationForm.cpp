/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:02:04 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/11 15:20:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)  : AForm("Shrubbery", 145, 137) {
	this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& original) : AForm() {
	*this = original;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& value) {
	if (this != &value)
		*this = value;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	try {
		if (this->getIsSigned())
			if (executor.getGrade() >= this->getGradeToSign())
				executor.executeForm(*this);
			else
				throw Bureaucrat::GradeTooLowException();
		else
			throw "Form is not signed!";
	}
	catch (const Bureaucrat::GradeTooLowException& error) {
		std::cout  << error.what() << std::endl;
	}
}

void ShrubberyCreationForm::executeAction(Bureaucrat const & executor) const {
	try {
		if (this->getIsSigned())
		{
			if (executor.getGrade() >= this->getGradeToExecute())
			{
				std::ofstream thisFile(this->_target.c_str());
				if (thisFile.is_open())
				{
					thisFile << "               ,@@@@@@@," << std::endl;
					thisFile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
					thisFile << "    ,&&&&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
					thisFile << "   ,%&&&&&%&&%,@@@@@@@/@@@88\\88888/88'" << std::endl;
					thisFile << "   %&&%&%&/%&&%@@@@@/ /@@@88888\\88888'" << std::endl;
					thisFile << "   %&&%/ %&&&&&@@@ V /@@' `88\\8 `/88'" << std::endl;
					thisFile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
					thisFile << "       |o|        | |         | |" << std::endl;
					thisFile << "       |.|        | |         | |" << std::endl;
					thisFile << "___vV_/ ._V/_Vv/_/  ,\\_//__\\v/.  \\______" << std::endl;
					thisFile.close();
				}
				else
					std::cout << "Error opening file!" << std::endl;
				std::cout << executor.getName() << " executed " <<  this->getName() << std::endl;
			}
			else
				throw GradeTooLowException();
		}
		else
			throw "Shrubbery Form not signed!";
	}
	catch (const Bureaucrat::GradeTooLowException& error) {
		std::cout  << error.what() << std::endl;
	}	
}