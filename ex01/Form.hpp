/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:37:30 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/07 19:49:33 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FORM_
# define _FORM_

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Form {
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
public:
	std::string getName();
	bool getIsSigned();
	int getGradeToSign();
	int getGradeToExecute();
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();	
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	void beSigned(Bureaucrat &obj);
	Form();
	Form(std::string _name, const int _gradeToSign, const int _gradeToExecute);
	~Form();
	Form& operator=(const Form& value);
	Form(const Form& copy);
};

std::ostream& operator<<(std::ostream& o, Form& value);

#endif
