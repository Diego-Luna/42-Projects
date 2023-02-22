/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:53:22 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/21 21:44:11 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"



// Constructors
Bureaucrat::Bureaucrat(void) : _name("NONE"), _grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade): _name(_name), _grade(_grade) {
	std::cout << "Bureaucrat name nad greade constructor called" << std::endl;
	if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
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

std::string Bureaucrat::getName(void) const {
    return (this->_name);
}
void Bureaucrat::setName(const std::string& desired_name) {
    this->_name = desired_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::minusGrade(int increment) {
	if (this->_grade - increment < 1){
		throw Bureaucrat::GradeTooLowException();
	}else{
		this->_grade -= increment;
	}
}

void Bureaucrat::addGrade(int decrement) {
	if (this->_grade + decrement > 150){
		throw Bureaucrat::GradeTooHighException();
	}else{
		this->_grade += decrement;
	}
}

// try{} cath{}
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Asked grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Asked grade is too low";
}

// operators

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
    if (this->_grade < 1)
        throw GradeTooHighException();
    else if (this->_grade > 150)
        throw GradeTooLowException();
	else
   		this->_grade = obj.getGrade();
	this->_name = obj.getName();
    return *this;
}

// ostream
std::ostream& operator<<(std::ostream& out, const Bureaucrat& value) {
    out << value.getName() << ", Bureaucrat grade " << value.getGrade();
    return out;
}
