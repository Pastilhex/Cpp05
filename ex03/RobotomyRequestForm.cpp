/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:02:32 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/12 16:15:29 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Jarbas", 72, 45) {
	this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Jarbas", 72, 45) {
	this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & original) : AForm(original), _target(original._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm & obj) {
    if (this != &obj)
        *this = obj;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned())
	{
		if (executor.getGrade() <= this->getGradeToExecute()) 
		{
			if (rand() % 2) 
				std::cout << executor.getName() << " has been robotomized successfully." << std::endl;
			else 
				std::cout <<  executor.getName() << " has not been robotomized successfully." << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else
		throw FormNotSignedException();
}
