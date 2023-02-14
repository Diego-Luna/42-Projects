/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:53:29 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/14 13:01:02 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Weapon.hpp"

Weapon::Weapon(std::string 	newType){
	this->_type = newType;
	return;
}

Weapon::~Weapon(void){
	return;
}

std::string	&Weapon::getType(void){
	return (this->_type);
}

void	Weapon::setType(std::string newType)
{
	this->_type = newType;
}
