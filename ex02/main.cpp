/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:00:49 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/12 18:24:03 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	{
		std::cout << "*******************************************" << std::endl;
		std::cout << "* Copy Constructor && Assignment Operator *" << std::endl;
		std::cout << "*******************************************" << std::endl;
		try
		{
			Bureaucrat ivo("Ivo", 137);
			Bureaucrat joao(ivo);
			Bureaucrat heitor;
			heitor = ivo;

			std::cout << ivo << std::endl;
			std::cout << joao << std::endl;
			std::cout << heitor << std::endl;
			std::cout << std::endl;
			
			ShrubberyCreationForm shrubberyForm("Home");
			ShrubberyCreationForm testForm(shrubberyForm);
			ShrubberyCreationForm assignForm;
			assignForm = shrubberyForm;
			std::cout << shrubberyForm << std::endl;
			std::cout << testForm << std::endl;
			std::cout << assignForm << std::endl;
			std::cout << std::endl;
		}
		catch (const std::exception& error) { std::cout  << error.what() << std::endl; }
	}

	{
		std::cout << "*************************************************" << std::endl;
		std::cout << "* Grade to Sign & Grade to Execute Successfully *" << std::endl;
		std::cout << "*************************************************" << std::endl;
		try
		{
			std::srand(std::time(0));
			Bureaucrat ivo("Ivo", 137);
			Bureaucrat joao(ivo);
			{
				ShrubberyCreationForm shrubberyForm("Home");
				ivo.signForm(shrubberyForm);
				ivo.executeForm(shrubberyForm);
				shrubberyForm.execute(joao);
			}
		}
		catch (const std::exception& error)
		{
			std::cout  << error.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "****************************************************" << std::endl;
		std::cout << "* Grade to Sign & No Grade to Execute Successfully *" << std::endl;
		std::cout << "****************************************************" << std::endl;
		try
		{
			std::srand(std::time(0));
			Bureaucrat ivo("Ivo", 72);
			Bureaucrat joao("Joao", 46);
			{
				RobotomyRequestForm robotForm("Jarbas FX100");
				ivo.signForm(robotForm);
				ivo.executeForm(robotForm);
				robotForm.execute(joao);
			}
		}
		catch (const std::exception& error)
		{
			std::cout  << error.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "*******************************************************" << std::endl;
		std::cout << "* No Grade to Sign & No Grade to Execute Successfully *" << std::endl;
		std::cout << "*******************************************************" << std::endl;
		try
		{
			Bureaucrat ivo("Ivo", 26);
			Bureaucrat joao("Joao", 6);
			PresidentialPardonForm pardonForm("XPTO");
			ivo.signForm(pardonForm);
			ivo.executeForm(pardonForm);
			joao.executeForm(pardonForm);
			ivo.executeForm(pardonForm);
		}
		catch (const std::exception& error)
		{
			std::cout  << error.what() << std::endl;
		}
	}
	return 0;
}
