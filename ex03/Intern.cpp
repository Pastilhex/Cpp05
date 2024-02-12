/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:31:36 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/12 21:15:30 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& original) {
	*this = original;
}

Intern& Intern::operator=(const Intern& obj) {
	if (this != &obj)
		*this = obj;
	return *this;
}

AForm* Intern::makeForm(std::string formName, std::string formTarget) {
    AForm* newForm = 0;
    std::string namesArray[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    for (size_t i = 0; i < sizeof(namesArray) / sizeof(namesArray[0]); i++) {
        if (namesArray[i] == formName) {
            switch (i) {
                case 0:
                    newForm = new ShrubberyCreationForm(formTarget);
                    break;
                case 1:
                    newForm = new RobotomyRequestForm(formTarget);
                    break;
                case 2:
                    newForm = new PresidentialPardonForm(formTarget);
                    break;
                default:
                    std::cout << "Intern was not able to create " << formName << std::endl;
                    return 0;
            }
        }
    }
    if (newForm) 
        std::cout << "Intern creates " << formName << std::endl;
    else 
        std::cout << "Intern was not able to create " << formName << std::endl;
    return newForm;
}

