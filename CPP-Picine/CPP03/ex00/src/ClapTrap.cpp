/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:26:44 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/21 10:33:44 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

// Basic

ClapTrap::ClapTrap(void) : _name("No name"), _hit(10), _energy(10), _attack(0){
	// std::cout << "ClapTrap Default constructor called" << std::endl;
	return;
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _attack(0){
	// std::cout << "ClapTrap Default constructor called" << std::endl;
	return;
}
ClapTrap::ClapTrap(ClapTrap const &src) {
	// std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
	return;
}
ClapTrap::~ClapTrap(void) {
	// std::cout << "ClapTrap destructor called" << std::endl;
	return;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src){
	this->_name = src._name;
	this->_hit = src._hit;
	this->_energy = src._energy;
	this->_attack = src._attack;
	return (*this);
}

// exercise
void ClapTrap::attack(const std::string& target){
	if (this->_hit <= 0){
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
	} else if (this->_energy <= 0){
		std::cout << "ClapTrap " << this->_name << " is out of energy!" << std::endl;
	} else {
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack << " points of damage!" << std::endl;
		this->_energy -= 1;
	}
}


void ClapTrap::takeDamage(unsigned int amount){

	if (this->_hit <= 0){
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
	this->_hit -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_hit <= 0){
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
	} else if (this->_energy <= 0){
		std::cout << "ClapTrap " << this->_name << " is out of energy!" << std::endl;
	}else{
		std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points!" << std::endl;
		this->_hit += amount;
		this->_energy -= 1;
	}
}

std::string ClapTrap::getName(void){
	return (this->_name);
}
