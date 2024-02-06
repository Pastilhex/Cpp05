/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:01:20 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/06 17:22:25 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {
}

std::string Bureaucrat::getName() {
    return this->_name;
}

int Bureaucrat::getGrade() {
    return this->_grade;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade to high!");
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade to low!");
}

Bureaucrat::Bureaucrat(const Bureaucrat& original) {
	*this = original;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& value) {
	if (this != &value)
		*this = value;
	return *this;
}

std::ostream& operator<<(std::ostream& o, Bureaucrat& value){
	o << value.getName() << ", bureaucrat grade " << value.getGrade();
	return o;
}

void Bureaucrat::incGrade() {
	int inc = getGrade();
	this->_grade -= inc--;
}

void Bureaucrat::decGrade() {
	int dec = getGrade();
	this->_grade += dec++;
}
