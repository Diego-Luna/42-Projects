
#include "./ScavTrap.hpp"

void	printPlayer_ClapTrap(ClapTrap *player)
{
	std::cout << " ->> printPlayer_ClapTrap" << std::endl;
	std::cout << "Name: " << player->getName() << std::endl;
	std::cout << "Hit: " << player->getHit() << std::endl;
	std::cout << "Energy: " << player->getEnergy() << std::endl;
	std::cout << "Attack: " << player->getAttack() << std::endl;
	std::cout << " ->> printPlayer_ClapTrap\n" << std::endl;
}

void	printPlayer_ScavTrap(ScavTrap *player)
{
	std::cout << " *-*->> printPlayer_ClapTrap" << std::endl;
	std::cout << "Name: " << player->getName() << std::endl;
	std::cout << "Hit: " << player->getHit() << std::endl;
	std::cout << "Energy: " << player->getEnergy() << std::endl;
	std::cout << "Attack: " << player->getAttack() << std::endl;
	std::cout << " *-*->> printPlayer_ClapTrap\n" << std::endl;
}

int main(void) {
  ClapTrap	first;
	ScavTrap	second("BabyShark");

	printPlayer_ClapTrap(&first);
	printPlayer_ScavTrap(&second);

	first.attack(second.getName());
	second.attack(first.getName());
	second.guardGate();

	printPlayer_ClapTrap(&first);
	printPlayer_ScavTrap(&second);
}
