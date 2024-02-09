/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:02:04 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/09 13:46:07 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)  : AForm("Shrubbery", 135, 147) {
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
			if (executor.getGrade() <= this->getGradeToSign())
				executor.executeForm(*this);
			else
				throw GradeTooLowException();
		else
			throw "Form is not signed!";
	}
	catch (const Bureaucrat::GradeTooLowException& error) {
		std::cout  << error.what() << std::endl;
	}
}

void ShrubberyCreationForm::executeAction() const {
	std::ofstream thisFile(this->_target);
	if (thisFile.is_open()) {
		thisFile << "               ,@@@@@@@,";
		thisFile << "       ,,,.   ,@@@@@@/@@,  .oo8888o.";
		thisFile << "    ,&&&&%&&%,@@@@@/@@@@@@,8888\\88/8o";
		thisFile << "   ,%&&&&&%&&%,@@@@@@@/@@@88\\88888/88'";
		thisFile << "   %&&%&%&/%&&%@@@@@/ /@@@88888\\88888'";
		thisFile << "   %&&%/ %&&&&&@@@ V /@@' `88\\8 `/88'";
		thisFile << "   `&%\\ ` /%&'    |.|        \\ '|8'";
		thisFile << "       |o|        | |         | |";
		thisFile << "       |.|        | |         | |";
		thisFile << "______/ ._\\//_/__/  ,\\_//__\\/.  \\______";
		thisFile.close();
	}
	else
		std::cout << "Error opening file!" << std::endl;
}
