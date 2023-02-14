/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:29:02 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/14 12:04:59 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie::Zombie(){
	// std::cout << "Zombie created" << std::endl;
	return;
}

Zombie::~Zombie(void){
	// std::cout << "Zombie destroyed" << std::endl;
	return;
}


void Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ" << std::endl;;
}

void Zombie::set_name(std::string name){
	this->_name = name;
}

/// normal funtions

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0 || name.empty())
	{
		return NULL;
	}

	Zombie *array = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		array[i].set_name(name);
	}
	return (array);
}