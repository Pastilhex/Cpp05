/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:00:49 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/12 11:34:51 by ialves-m         ###   ########.fr       */
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
		ShrubberyCreationForm shrubberyForm("Home");
		RobotomyRequestForm robotForm("Jarbas");
		PresidentialPardonForm pardonForm("Joao");

		// pardonForm.beSigned(obj);
		// obj.signForm(pardonForm);
		// pardonForm.execute(obj);
		// obj.executeForm(pardonForm);

		// robotForm.beSigned(obj);
		// obj.signForm(robotForm);
		// robotForm.execute(obj);

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
