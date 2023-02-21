/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:53:20 by diegofranci       #+#    #+#             */
/*   Updated: 2023/02/21 13:32:26 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
Cat::Cat(void) : Animal("Cat"), _brain(new Brain) {
	std::cout << "Cat default constructor called" << std::endl;
	return;
}

Cat::Cat(Cat const &src): Animal(),  _brain(new Brain) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
	return;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
	return;
}

// Basic

std::string Cat::getType(void) const {
	return this->_type;
}

void Cat::makeSound(void) const {
	std::cout << "Cat sound -> Meow!!" << std::endl;
	return;
}

// operators

Cat &Cat::operator=(Cat const &src) {
	std::cout << "Cat assignation operator called" << std::endl;
	this->_type = src._type;
	for (size_t i = 0; i < 100; i++)
	{
		this->_brain->ideas[i] = src._brain->ideas[i];
	}
	return *this;
}

