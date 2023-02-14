/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:29:02 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/14 13:27:24 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie::Zombie(std::string 	initial_name){
	std::cout << "Zombie created" << std::endl;
	this->_name = initial_name;
	return;
}

Zombie::~Zombie(void){
	std::cout << "Zombie destroyed" << std::endl;
	return;
}


void Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

/// normal funtions

Zombie* newZombie( std::string name ){
	Zombie *send;

	send = new Zombie(name);
	return (send);
}


void randomChump( std::string name ){
	Zombie tem(name);

	tem.announce();
}
