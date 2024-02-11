/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:01:17 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/11 16:37:21 by codespace        ###   ########.fr       */
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

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	std::string getName() const;
	int getGrade() const;
	void incGrade();
	void decGrade();
	void signForm(AForm &formObj);
	void executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat& value);

#endif
