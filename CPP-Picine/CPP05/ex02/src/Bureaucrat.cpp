/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:53:22 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/22 20:00:30 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat(void) : _name("NONE"), _grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(std::string const & _name, int _grade): _name(_name), _grade(_grade) {
	std::cout << "Bureaucrat name nad greade constructor called" << std::endl;
	if (_grade < 1){
		throw GradeTooHighException();
	}
  if (_grade > 150){
		throw GradeTooLowException();
	}
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src.getName()), _grade(src.getGrade()) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	if (_grade < 1){
		throw GradeTooHighException();
	}
  if (_grade > 150){
		throw GradeTooLowException();
	}
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

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade(int increment) {
	if (this->_grade - increment < 1){
		throw Bureaucrat::GradeTooHighException();
	}else{
		this->_grade -= increment;
	}
}

void Bureaucrat::decrementGrade(int decrement) {
	if (this->_grade + decrement > 150){
		throw Bureaucrat::GradeTooLowException();
	}else{
		this->_grade += decrement;
	}
}

void Bureaucrat::signForm(Form &src) const{
	try {
    src.beSigned(*this);
    std::cout << this->getName() << " signs " << src.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << this->getName() << " cannot sign " << src.getName() << " because " << e.what() << std::endl;
  }
}

// execute
void Bureaucrat::executeForm(Form const & form) {
	try{
		std::cout << getName() << " executes " << form.getName() << std::endl;
		form.execute(*this);
	}
	catch(std::exception& e){
		std::cout << getName() << " could not executes " << form.getName() << " because " << e.what() << std::endl;
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
  if (this->_grade < 1){
		throw GradeTooHighException();
	}
  else if (this->_grade > 150){
    throw GradeTooLowException();
	}
	else{
		this->_grade = obj.getGrade();
	}
  return *this;
}

// ostream
std::ostream& operator<<(std::ostream& out, const Bureaucrat& value) {
    out << value.getName() << ", Bureaucrat grade " << value.getGrade() << ".";
    return out;
}
