/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:57:59 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/20 13:49:05 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"


Fixed::Fixed(void) : _number(0){
	// std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const int value) : _number(value << _numberBits){
	// std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed(const float value) : _number(round( value * (float)( 1 << _numberBits) )){
	// std::cout << "Float constructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed &src)
{
	// std::cout << "Copy constructor called" << std::endl;

	*this = src;
	return;
}

Fixed &Fixed::operator=(const Fixed &nbr)
{
	// std::cout << "Assignation operator called" << std::endl;
	this->_number = nbr.getRawBits();
	return (*this);
}

Fixed::~Fixed(void){
	// std::cout << "Destructor called" << std::endl;
	return;
}

int Fixed::getRawBits(void) const{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_number);
}

float Fixed::toFloat( void ) const {
	return ((float)_number / (float)( 1 << _numberBits));
}

int Fixed::toInt( void ) const{
	return ( _number >> _numberBits);
}

// operators -> **********

Fixed Fixed::operator+(const Fixed &nbr){
	return Fixed(toFloat() + nbr.toFloat());
}
Fixed Fixed::operator-(const Fixed &nbr){
	return Fixed(toFloat() - nbr.toFloat());
}
Fixed Fixed::operator/(const Fixed &nbr){
	return Fixed(toFloat() / nbr.toFloat());
}
Fixed Fixed::operator*(const Fixed &nbr){
	return Fixed(toFloat() * nbr.toFloat());
}

Fixed &Fixed::operator++(void){
	this->_number++;
	return *this;
}
Fixed Fixed::operator++(int){
	Fixed tem(*this);
	++(*this);
	return tem;
}

Fixed &Fixed::operator--(){
	this->_number--;
	return *this;
}
Fixed Fixed::operator--(int){
	Fixed tem(*this);
	--(*this);
	return tem;
}


bool Fixed::operator<(const Fixed &nbr) const{
	// if (this->toFloat() < nbr.toFloat())
	if (this->_number < nbr.getRawBits())
	{
		return true;
	}
	return false;
}
bool Fixed::operator<=(const Fixed &nbr) const{
	// if (this->toFloat() <= nbr.toFloat())
	if (this->_number <= nbr.getRawBits())
	{
		return true;
	}
	return false;
}

bool Fixed::operator>(const Fixed &nbr) const{
	// if (this->toFloat() > nbr.toFloat())
	if (this->_number > nbr.getRawBits())
	{
		return true;
	}
	return false;
}
bool Fixed::operator>=(const Fixed &nbr) const{
	// if (this->toFloat() >= nbr.toFloat())
	if (this->_number >= nbr.getRawBits())
	{
		return true;
	}
	return false;
}

bool Fixed::operator==(const Fixed &nbr) const{
	// if (this->toFloat() == nbr.toFloat())
	if (this->_number == nbr.getRawBits())
	{
		return true;
	}
	return false;
}
bool Fixed::operator!=(const Fixed &nbr) const{
	// if (this->toFloat() != nbr.toFloat())
	if (this->_number != nbr.getRawBits())
	{
		return true;
	}
	return false;
}


// Max -> **********
Fixed&	Fixed::max(Fixed&a, Fixed&b){
	return ((a > b)? a:b);
}
const Fixed&	Fixed::max(const Fixed&a, const Fixed&b){
	return ((a > b)? a:b);
}

// Min -> **********

Fixed&	Fixed::min(Fixed&a, Fixed&b){
	return ((a < b)? a:b);
}
const Fixed&	Fixed::min(const Fixed&a, const Fixed&b){
	return ((a < b)? a:b);
}

std::ostream &operator<<(std::ostream &out, Fixed const instance)
{
	out << instance.toFloat();
	return out;
}


