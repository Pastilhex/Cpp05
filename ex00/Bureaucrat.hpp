/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:01:17 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/06 17:17:23 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BUREAUCRAT_
# define _BUREAUCRAT_

#include <iostream>
#include <string>

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
};

std::ostream& operator<<(std::ostream& o, Bureaucrat& value);

#endif
