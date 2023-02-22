/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:47:41 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/22 17:17:56 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors
Form::Form(void) :
_name("NONE"),
_target("NONE"),
_signed(false),
_gradeSingIn(150),
_gradeExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
	return;
}

Form::Form(std::string const & _name, std::string const & _target,bool	_signed, int _gradeSingIn, int _gradeExecute): 
_name(_name),
_target(_target),
_signed(_signed),
_gradeSingIn(_gradeSingIn),
_gradeExecute(_gradeExecute)
{
	std::cout << "Form name nad greade constructor called" << std::endl;
	if (_gradeSingIn < 1 || _gradeExecute < 1 ){
		throw GradeTooHighException();
	}
  if (_gradeSingIn > 150 || _gradeExecute > 150){
		throw GradeTooLowException();
	}
	return;
}

Form::Form(Form const &src):
	_name(src._name),
	_target(src._target),
	_signed(src._signed),
	_gradeSingIn(src._gradeSingIn),
	_gradeExecute(src._gradeExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
	if (_gradeSingIn < 1 || _gradeExecute < 1 ){
		throw GradeTooHighException();
	}
  if (_gradeSingIn > 150 || _gradeExecute > 150){
		throw GradeTooLowException();
	}
	return;
}

Form::~Form(void) {
	std::cout << "Form destructor called" << std::endl;
	return;
}

// Basic

std::string Form::getName(void) const {
    return (this->_name);
}
std::string Form::getTarget(void) const {
    return (this->_target);
}
bool 					Form::getSigned(void) const{
	return (this->_signed);
}
int         	Form::getGradeSingIn(void) const{
	return (this->_gradeSingIn);
}
int         	Form::getGradeExecute(void) const{
	return (this->_gradeExecute);
}

void					Form::beSigned(const Bureaucrat &src){
	if (src.getGrade() > this->_gradeSingIn){
		throw Form::GradeTooLowException();
	}else{
		this->_signed = true;
	}

}


// try{} cath{}
const char* Form::GradeTooHighException::what() const throw() {
    return "User can't acces file, grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "User can't acces file, grade is too low";
}

// operators

Form& Form::operator=(const Form& obj) {
	this->_signed = obj.getSigned();
  return *this;
}

// ostream
std::ostream& operator<<(std::ostream& out, const Form& value) {
    out << "form name:" << value.getName() << " require " << value.getGradeSingIn() << "\n"
      << "to be signed and require " << value.getGradeExecute() << " to be executed and it "
      << (value.getSigned() ? "is signed" : "is not signed");
    return out;
}
