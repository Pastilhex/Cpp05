/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:00:49 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/12 21:17:52 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		try
		{
			Bureaucrat ivo("Ivo", 137);
			Intern someRandomIntern;
			AForm* one;
			AForm* two;
			AForm* three;

			one = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
			two = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
			three = someRandomIntern.makeForm("PresidentialPardon", "Bender");
			if (one)
				one->execute(ivo);
			if (two)
				two->execute(ivo);
			if (three)
				three->execute(ivo);
		}
		catch (const std::exception& error)
		{
			std::cout  << error.what() << std::endl;
		}
	}
	return 0;
}
