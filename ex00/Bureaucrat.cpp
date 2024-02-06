/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:01:20 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/05 16:12:31 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade){
    if (grade < 1)
        throw "Bureaucrat::GradeTooHighException";
    else if (grade > 150)
        throw "Bureaucrat::GradeTooLowException";

}

Bureaucrat::~Bureaucrat(){
}

std::string Bureaucrat::getName(){
    return this->name;
}

int Bureaucrat::getGrade(){
    return this->grade;
}
