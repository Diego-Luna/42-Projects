/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:58:47 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/14 12:07:01 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int main(void) {

	Zombie	*zombie;
	int		number;
	std::string	name;

	std::cout << "\n -> How much zombies do you want?" << std::endl;
	std::cin >> number;
	std::cout << "\n -> What is the name of your zombies?" << std::endl;
	std::cin >> name;

	zombie = zombieHorde(number, name);
	if (!zombie)
	{
		return 0;
	}
	for (int i = 0; i < number; i++)
		zombie[i].announce();

	delete [] zombie;
	return (0);
}
