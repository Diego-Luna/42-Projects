/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:19:01 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/14 15:59:39 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanA.hpp"

HumanA::HumanA(std::string 	name, Weapon &_weapon) : _name(name), _weapon(_weapon)  {
	return;
}

HumanA::~HumanA(void){
	return;
}

void HumanA::attack(void){

	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
