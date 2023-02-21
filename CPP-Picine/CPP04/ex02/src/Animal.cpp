/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:05:26 by diegofranci       #+#    #+#             */
/*   Updated: 2023/02/21 13:28:59 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors
Animal::Animal(void) : _type("NONE") {
	std::cout << "Animal default constructor called" << std::endl;
	return;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal name constructor called" << std::endl;
	return;
}

Animal::Animal(Animal const &src) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
	return;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
	return;
}

// Basic

std::string Animal::getType(void) const {
	return this->_type;
}

void Animal::makeSound(void) const {
	std::cout << "Animal sound" << std::endl;
	return;
}

// operators

Animal &Animal::operator=(Animal const &src) {
	std::cout << "Animal assignation operator called" << std::endl;
	this->_type = src._type;
	return *this;
}

