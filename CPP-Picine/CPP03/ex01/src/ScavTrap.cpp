/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:55:58 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/21 10:33:38 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

// Basic
ScavTrap::ScavTrap(void) : ClapTrap() {
	this->_name = "No name";
	this->_type = "ScavTrap";
	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
	return;
}
ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 20;
	this->_type = "ScavTrap";
	std::cout << "ScavTrap constructor wirh name called" << std::endl;
	return;
}
ScavTrap::ScavTrap(ScavTrap const &src) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
	return;
}
ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called" << std::endl;
	return;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src){
	if (!(this == &src)){
		this->_name = src._name;
		this->_hit = src._hit;
		this->_energy = src._energy;
		this->_attack = src._attack;
	}
	return (*this);
}

void	ScavTrap::guardGate(void) {
	std::cout << this->_type << " " << this->_name << " has entered in Gate keeper mode" << std::endl;
}