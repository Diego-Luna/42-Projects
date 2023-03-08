/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 07:25:13 by diegofranci       #+#    #+#             */
/*   Updated: 2023/03/08 09:33:46 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	this->_form[0] = "presidential request";
	this->_form[1] = "robotomy request";
	this->_form[2] = "shrubbery request";
}

Intern::Intern(const Intern& src) {
	if (&src != this){
		this->_form[0] = src._form[0];
		this->_form[1] = src._form[1];
		this->_form[2] = src._form[2];
	}
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern& src) {
	if (&src != this){
		this->_form[0] = src._form[0];
		this->_form[1] = src._form[1];
		this->_form[2] = src._form[2];
	}
	return *this;
}

Form *Intern::makeForm(std::string name, std::string target) {
	for (int i = 0; i < 3; i++) {
		if (name == this->_form[i]) {
			std::cout << "Intern creates " << name << std::endl;
			if (i == 0)
				return new PresidentialPardonForm(target);
			else if (i == 1)
				return new RobotomyRequestForm(target);
			else if (i == 2)
				return new ShrubberyCreationForm(target);
		}
	}
	std::cout << "Intern can't create " << name << std::endl;
	return NULL;
}
