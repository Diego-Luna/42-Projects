/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:24:50 by diegofranci       #+#    #+#             */
/*   Updated: 2023/02/21 10:43:11 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void	printPlayer(ClapTrap *player, ClapTrap *player2, ClapTrap *player3)
{
	std::cout << "--> ClapTrap "<< std::endl;
	std::cout << "Name: " << player->getName() << std::endl;
	std::cout << "Hit: " << player->getHit() << std::endl;
	std::cout << "Energy: " << player->getEnergy() << std::endl;
	std::cout << "Attack: " << player->getAttack() << std::endl;
	std::cout << "--> ClapTrap \n"<< std::endl;

	std::cout << "**> ScavTrap"<< std::endl;
  std::cout << "Name: " << player2->getName() << std::endl;
	std::cout << "Hit: " << player2->getHit() << std::endl;
	std::cout << "Energy: " << player2->getEnergy() << std::endl;
	std::cout << "Attack: " << player2->getAttack() << std::endl;
	std::cout << "**> ScavTrap \n"<< std::endl;

	std::cout << "===> FragTrap"<< std::endl;
  std::cout << "Name: " << player3->getName() << std::endl;
	std::cout << "Hit: " << player3->getHit() << std::endl;
	std::cout << "Energy: " << player3->getEnergy() << std::endl;
	std::cout << "Attack: " << player3->getAttack() << std::endl;
	std::cout << "===> FragTrap \n"<< std::endl;
}

int main(void)
{
	ClapTrap	first;
	ScavTrap	second("🤟");
	FragTrap	third("😂");

	printPlayer(&first, &second, &third);

	first.attack(second.getName());
	second.guardGate();
	first.beRepaired(3);

	second.attack(third.getName());
	third.takeDamage(3);
	third.highFivesGuys();

  third.attack(third.getName());
	third.takeDamage(3);
	third.highFivesGuys();

  printPlayer(&first, &second, &third);

	return (0);
}