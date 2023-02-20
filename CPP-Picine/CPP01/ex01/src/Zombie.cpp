/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:29:02 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/20 11:20:26 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie::Zombie(){
	// std::cout << "Zombie created" << std::endl;
	return;
}

Zombie::~Zombie(void){
	// std::cout  << this->_name << " Zombie destroyed" << std::endl;
	return;
}


void Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;;
}

void Zombie::set_name(std::string name){
	this->_name = name;
}
