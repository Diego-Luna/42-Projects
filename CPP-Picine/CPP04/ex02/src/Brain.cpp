/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:03:36 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/21 12:10:04 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors
Brain::Brain(void) {
	std::cout << "Brain default constructor called" << std::endl;
	return;
}

Brain::Brain(Brain const &src) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
	return;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called" << std::endl;
	return;
}

// operators

Brain &Brain::operator=(Brain const &src) {
	std::cout << "Brain assignation operator called" << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = src.ideas[i];
	}
	return *this;
}

