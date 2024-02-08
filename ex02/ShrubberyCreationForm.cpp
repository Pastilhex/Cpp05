/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:02:04 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/08 14:50:11 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::beSigned(Bureaucrat & obj) {
	try
	{
		if (obj.getGrade() <= this->getGradeToSign())
			this->_isSigned = true;
		else
			throw ShrubberyCreationForm::GradeTooLowException();
	}
 	catch(const ShrubberyCreationForm::GradeTooLowException& error)
	{
		std::cout  << error.what() << std::endl;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& original) : AForm() {
	*this = original;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& value) {
	if (this != &value)
		*this = value;
	return *this;
}

std::string ShrubberyCreationForm::getName() {
	return this->getName();
}

bool ShrubberyCreationForm::getIsSigned() {
	return this->getIsSigned();
}

int ShrubberyCreationForm::getGradeToSign() {
	return this->getGradeToSign();
}

int ShrubberyCreationForm::getGradeToExecute() {
	return this->getGradeToExecute();
}

