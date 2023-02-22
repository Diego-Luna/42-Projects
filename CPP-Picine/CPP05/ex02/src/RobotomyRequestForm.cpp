/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:24:35 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/22 17:39:52 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
	Form("RobotomyRequestForm", "Default", false, 72, 45)
{
	// std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src):
	Form(
		src.getName(),
		src.getTarge(),
		src.getSigned(),
		src.getGradeSingIn(),
		src.getGradeExecute()
	)
{
	// std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & targert):
	Form(
		"RobotomyRequestForm",
		targert,
		false,
		72,
		45
	)
{
	// std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	return;
}
RobotomyRequestForm::~RobotomyRequestForm(void){
	return;
}

RobotomyRequestForm		&RobotomyRequestForm::operator=(Bureaucrat const & src){
	return *this;
}

