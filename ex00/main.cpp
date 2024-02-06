/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:00:49 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/06 17:18:40 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat obj("Ivo", 1);
		obj.decGrade();
		std::cout << obj << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& error)
	{
		std::cout  << error.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& error)
	{
		std::cout  << error.what() << std::endl;
	}
	

	// try
	// {
	// 	Bureaucrat obj1("ivo", 151);
	// }
	// catch (const char * txt)
	// {
	// 	std::cout << "Bureaucrat::" << txt << std::endl;
	// }
	return 0;
}
