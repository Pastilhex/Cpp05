/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:02:06 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/08 14:53:39 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
	std::string getName();
	bool getIsSigned();
	int getGradeToSign();
	int getGradeToExecute();
	void beSigned(Bureaucrat &obj);
	void setIsSigned(bool isSigned);

	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string name, const int gradeToSign, const int gradeToExecute) : AForm(name, gradeToSign, gradeToExecute) {};
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm & obj);
	ShrubberyCreationForm(const ShrubberyCreationForm& original);
};
