/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:47:57 by diegofranci       #+#    #+#             */
/*   Updated: 2023/02/18 19:18:42 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    std::cout << "Default FragTrap constructor FragTrap" << std::endl;

    _hit = 100;
    _energy = 100;
    _attack = 30;

    return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Default FragTrap constructor with name called" << std::endl;

    _hit = 100;
    _energy = 100;
    _attack = 30;

    return ;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
    std::cout << "Copy FragTrap constructor called" << std::endl;

    *this = src;
    return;
}

FragTrap::~FragTrap(void)
{
    std::cout << "Destructor FragTrap called" << std::endl;

    return;
}


// funcions

FragTrap    &FragTrap::operator=(const FragTrap &src)
{
    if (this != &src)
    {
        this->_name = src._name;
        this->_hit = src._hit;
        this->_energy = src._energy;
        this->_attack = src._attack;
    }
    return (*this);
}

void        FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " gives a high five" << std::endl;
}
