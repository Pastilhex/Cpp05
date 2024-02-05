/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:01:17 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/05 07:08:47 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BUREAUCRAT_
# define _BUREAUCRAT_

#include <iostream>
#include <string>

class Bureaucrat {
public:
    const std::string name;
    int grade;
    Bureaucrat(std::string name, int grade);
    
    ~Bureaucrat();
    std::string getName();
    int getGrade();
    void GradeTooHighException();
    void GradeTooLowException();
};

#endif