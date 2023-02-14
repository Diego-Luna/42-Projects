/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:52:32 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/14 16:06:24 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanB.hpp"

HumanB::HumanB(std::string 	name) : _name(name){
	return;
}

HumanB::~HumanB(void){
	return;
}

// void setWeapon(Weapon &weapon);
void	HumanB::setWeapon(Weapon &weapon){
	this->_weapon = &weapon;
}

void HumanB::attack(void){

	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
