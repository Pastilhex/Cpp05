/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:31:25 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/12 19:50:35 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INTERN_
# define _INTERN_

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class AForm;

class Intern {
private:

public:
	Intern();
	~Intern();
	Intern(const Intern&);
	Intern& operator=(const Intern&);
	AForm* makeForm(std::string formName, std::string formTarget);
};

#endif
