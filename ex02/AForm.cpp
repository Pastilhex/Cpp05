/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:37:40 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/08 14:51:55 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char * AForm::GradeTooHighException::what() const throw() {
	return "Grade to high!";
}

const char * AForm::GradeTooLowException::what() const throw() {
	return "Grade to low!";
}

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {}

AForm::~AForm() {}

std::ostream& operator<<(std::ostream& o, AForm& value) {
    o << value.getName() << " "
      << (value.getIsSigned() ? "Signed" : "Not signed") << " "
      << "Grade to sign: " << value.getGradeToSign() << " "
      << "Grade to execute: " << value.getGradeToExecute();
    return o;
}

std::string AForm::getName() {
	return this->_name;
}

bool AForm::getIsSigned() {
	return this->_isSigned;
}

int AForm::getGradeToSign() {
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() {
	return this->_gradeToExecute;
}

void AForm::setIsSigned(bool isSigned) {
	this->_isSigned = isSigned;
}
