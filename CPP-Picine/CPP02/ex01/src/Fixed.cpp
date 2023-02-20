/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:57:59 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/20 15:15:14 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"


// basic

Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &newValue) {
	std::cout << "Copy constructor called" << std::endl;
	*this = newValue;
}

Fixed::Fixed(const int nbr) : _value(nbr << _bits){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nbr) : _value(roundf(nbr * (float)(1 << _bits))) {
	std::cout << "Float constructor called" << std::endl;
}

// Exercise

Fixed &Fixed::operator=(const Fixed &nbr) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &nbr)
	{
		this->_value = nbr.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

int Fixed::toInt(void) const {
	return this->_value >> _bits;
}

float Fixed::toFloat(void) const {
	return (float)this->_value / (float)(1 << _bits);
}

std::ostream &operator<<(std::ostream &out, Fixed const &nbr) {
	out << nbr.toFloat();
	return out;
}
