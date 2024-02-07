/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:37:40 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/07 19:49:50 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char * Form::GradeTooHighException::what() const throw() {
	return "Grade to high!";
}

const char * Form::GradeTooLowException::what() const throw() {
	return "Grade to low!";
}

void Form::beSigned(Bureaucrat &obj) {
	try
	{
		if (obj.getGrade() <= this->getGradeToSign())
			this->_isSigned = true;
		else
			throw Form::GradeTooLowException();
	}
 	catch(const Form::GradeTooLowException& error)
	{
		std::cout  << error.what() << std::endl;
	}
}

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {}

Form::~Form() {}

Form::Form(const Form& copy) : _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
	*this = copy;
}

Form& Form::operator=(const Form& value) {
	if (this != &value)
		*this = value;
	return *this;
}

std::string Form::getName() {
	return this->_name;
}

bool Form::getIsSigned() {
	return this->_isSigned;
}

int Form::getGradeToSign() {
	return this->_gradeToSign;
}

int Form::getGradeToExecute() {
	return this->_gradeToExecute;
}

std::ostream& operator<<(std::ostream& o, Form& value) {
    o << value.getName() << " "
      << (value.getIsSigned() ? "Signed" : "Not signed") << " "
      << "Grade to sign: " << value.getGradeToSign() << " "
      << "Grade to execute: " << value.getGradeToExecute();
    return o;
}
