/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:02:58 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/12 16:15:37 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Pardon", 25, 5) {
	this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Pardon", 25, 5) {
    this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& original) : AForm(original), _target(original._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	if (this != &obj)
		*this = obj;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned())
		if (executor.getGrade() <= this->getGradeToExecute())
            std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		else
			throw GradeTooLowException();
	else
		throw FormNotSignedException();
}
