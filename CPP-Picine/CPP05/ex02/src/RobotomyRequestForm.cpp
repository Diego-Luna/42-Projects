/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:24:35 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/22 20:10:10 by diegofranci      ###   ########.fr       */
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
		src.getTarget(),
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

// RobotomyRequestForm		&RobotomyRequestForm::operator=(Bureaucrat const & src){
// 	return *this;
// }

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm&src) {
	(void)src;
	return *this;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const {

	validateExecute(executor);
	std::cout << "ZZZZZZZZZZZZZ crack oups.... ZZZzZZZZZZZZZZZzZZ ok...c'Est bon...ZZZZZzZZZZZZZZZZZZzZZZZZzZZ" << std::endl;
	srand(time(NULL));
	bool rand = (std::rand() % 2);
	if (rand)
		std::cout << getTarget() << " the terminator have been robotomizated" << std::endl;
	else
		std::cout << getTarget() << " robotomization failed" << std::endl;
}
