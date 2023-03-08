/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:32:58 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/08 13:51:19 by dluna-lo         ###   ########.fr       */
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
			switch(i) {
			  case 0:
			    return new PresidentialPardonForm(target);
			    break;
			  case 1:
			    return new RobotomyRequestForm(target);
			    break;
			  case 2:
			    return new ShrubberyCreationForm(target);
			    break;
			  default:
			    break;
			}
		}
	}
	// std::cout << "Sorry, Intern can't create name: " << name << " not valid" << std::endl;
	throw Intern::NotValid();
	return NULL;
}


const char* Intern::NotValid::what() const throw() {
    return "Sorry, Intern can't create name not valid";
}