/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:01:17 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/08 11:58:35 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BUREAUCRAT_
# define _BUREAUCRAT_

#include <exception>
#include <iostream>
#include <string>

class AForm;

class Bureaucrat {
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& original);
	Bureaucrat& operator=(const Bureaucrat& value);
	~Bureaucrat();
	std::string getName();
	int getGrade();
	void incGrade();
	void decGrade();
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	void signForm(AForm &formObj);
};

std::ostream& operator<<(std::ostream& o, Bureaucrat& value);

#endif
