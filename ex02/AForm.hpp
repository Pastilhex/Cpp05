/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:37:30 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/09 13:28:47 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AFORM_
# define _AFORM_

#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <string>

class AForm {
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
public:
	AForm();
	AForm(std::string name, const int _gradeToSign, const int _gradeToExecute);
	~AForm();
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();	
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	std::string getName();
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat &obj);
	virtual void execute(Bureaucrat const & executor) const = 0;
	virtual void executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& o, AForm& value);

#endif
