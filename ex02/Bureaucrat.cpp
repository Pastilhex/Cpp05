/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:01:20 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/11 15:19:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade to high!");
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade to low!");
}

Bureaucrat::Bureaucrat(const Bureaucrat& original) : _name(original._name), _grade(original._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& value) {
	if (this != &value)
		this->_grade = value._grade;
	return *this;
}

std::ostream& operator<<(std::ostream& o, Bureaucrat& value) {
	o << value.getName() << ", bureaucrat grade " << value.getGrade();
	return o;
}

void Bureaucrat::incGrade() {
	this->_grade--;
}

void Bureaucrat::decGrade() {
	this->_grade++;
}

void Bureaucrat::signForm(AForm &formObj) {
	if (formObj.getIsSigned())
		std::cout << this->getName() << " signed " << formObj.getName() << std::endl;
	else
		std::cout << this->getName() << " couldn't sign " << formObj.getName() << " because grade it's to low!" << std::endl;
}

void Bureaucrat::executeForm(AForm const & form) const {
	form.executeAction(*this);
}
