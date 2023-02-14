/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:50:46 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/14 11:52:24 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./Zombie.hpp"

int main(void) {
	Zombie	*zombie;

	zombie = newZombie("hello:(newZombie)");
	zombie->announce();
	delete zombie;
	randomChump("hi!, randomChump");
	return (0);
}
