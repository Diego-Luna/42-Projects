/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:19:26 by diegofranci       #+#    #+#             */
/*   Updated: 2023/02/21 13:22:30 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
Dog::Dog(void) : Animal("Dog"){
	std::cout << "Dog default constructor called" << std::endl;
	return;
}

Dog::Dog(Dog const &src) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
	return;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
	return;
}

// Basic

std::string Dog::getType(void) const {
	return this->_type;
}

void Dog::makeSound(void) const {
	std::cout << "Dog sound -> bark!!" << std::endl;
	return;
}

// operators

Dog &Dog::operator=(Dog const &src) {
	std::cout << "Dog assignation operator called" << std::endl;
	this->_type = src._type;
	return *this;
}

