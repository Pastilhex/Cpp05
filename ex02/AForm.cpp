/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:37:40 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/12 18:27:01 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm & obj) {
	(void) obj;
	return *this;
}

AForm::AForm(const AForm& original) : _name(original._name), _isSigned(original._isSigned), _gradeToSign(original._gradeToSign), _gradeToExecute(original._gradeToExecute) {
}

std::ostream& operator<<(std::ostream& o, AForm& value) {
    o << "Name:          " << value.getName() << "\n"
		<< "Signed:        " << (value.getIsSigned() ? "Signed \n" : "Not signed \n") 
		<< "Grade sign:    " << value.getGradeToSign() << "\n" 
		<< "Grade execute: " << value.getGradeToExecute() << "\n";
    return o;
}

const char * AForm::GradeTooHighException::what() const throw() {
	return "Execption: Grade to high!";
}

const char * AForm::GradeTooLowException::what() const throw() {
	return "Execption: Grade to low!";
}

const char * AForm::FormNotSignedException::what() const throw() {
	return "Execption: Form not signed!";
}

std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getIsSigned() const {
	return this->_isSigned;
}

int AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void AForm::beSigned(Bureaucrat & obj) {
	if (obj.getGrade() <= this->getGradeToSign())
		this->_isSigned = true;
	else
		throw Bureaucrat::GradeTooLowException();
}
