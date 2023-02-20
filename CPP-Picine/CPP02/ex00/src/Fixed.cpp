/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:57:59 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/20 14:58:34 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"


Fixed::Fixed(void) : _number(0){
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = src;
	return;
}

Fixed &Fixed::operator=(const Fixed &nbr)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_number = nbr.getRawBits();
	return (*this);
}


Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
	return;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_number);
}

void Fixed::setRawBits(int const raw) {
	this->_number = raw;
}