/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:37:30 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/08 14:52:03 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AFORM_
# define _AFORM_

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class AForm {
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
public:
	virtual std::string getName() = 0;
	virtual bool getIsSigned() = 0;
	void setIsSigned(bool isSigned);
	virtual int getGradeToSign() = 0;
	virtual int getGradeToExecute() = 0;
	virtual void beSigned(Bureaucrat &obj) = 0;
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();	
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	AForm();
	AForm(std::string name, const int _gradeToSign, const int _gradeToExecute);
	~AForm();
};

std::ostream& operator<<(std::ostream& o, AForm& value);

#endif
