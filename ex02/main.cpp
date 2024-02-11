/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:00:49 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/11 14:43:04 by codespace        ###   ########.fr       */
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
		ShrubberyCreationForm formObj("Shrubbery_House");
	
		formObj.beSigned(obj);
		obj.signForm(formObj);
		formObj.execute(obj);
		obj.executeForm(formObj);
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
