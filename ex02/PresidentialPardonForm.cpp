/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:02:58 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/11 18:24:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Pardon", 25, 5) {
    this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& original) : AForm() {
	*this = original;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	if (this != &obj)
		*this = obj;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned())
		if (executor.getGrade() >= this->getGradeToSign())
            std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}