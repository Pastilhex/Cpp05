/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:02:32 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/11 17:55:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Jarbas", 72, 45) {
	this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & original) : AForm() {
    *this = original;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm & obj) {
    if (this != &obj)
        *this = obj;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (this->getIsSigned())
    {
        if (executor.getGrade() >= this->getGradeToSign())
            std::cout << "Brrzzz... Brzzz... " << this->_target << " has been robotomized successfully 50% of the time." << std::endl;
        else
			std::cout << "Robotomy failed!" << std::endl;
    }
}