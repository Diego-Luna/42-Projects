/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:53:22 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/21 18:40:15 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat(void) : _name("NONE"), _grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(std::string _name, int	_grade) : _name(_name), _grade(_grade) {
	std::cout << "Bureaucrat name nad greade constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
	return;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat destructor called" << std::endl;
	return;
}

// Basic

std::string getName(void){

}
int getGrade(void){

}


// operators

Bureaucrat		&Bureaucrat::operator=(Bureaucrat const & src)
{
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	this->_name = src._name;
	this->_grade = src._grade;
	return *this;
}

// ostream
std::ostream& operator<<(std::ostream& out, const Bureaucrat& value) {
    out << value.getName() << " Bureaucrat grade = " << value.getGrade();
    return out;
}
