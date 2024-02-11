/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:00:49 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/11 18:25:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat obj("Ivo", 146);
		ShrubberyCreationForm shrubberyForm("Shrubbery_House");
		RobotomyRequestForm robotForm("Jarbas");
		PresidentialPardonForm pardonForm("Joao");

		pardonForm.beSigned(obj);
		obj.signForm(pardonForm);
		pardonForm.execute(obj);

		robotForm.beSigned(obj);
		obj.signForm(robotForm);
		robotForm.execute(obj);

		shrubberyForm.beSigned(obj);
		obj.signForm(shrubberyForm);
		shrubberyForm.execute(obj);
	}
	catch (const Bureaucrat::GradeTooHighException& error)
	{
		std::cout  << error.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& error)
	{
		std::cout  << error.what() << std::endl;
	}
	
	return 0;
}
