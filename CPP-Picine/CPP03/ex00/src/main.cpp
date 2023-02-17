/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:11:32 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/17 17:52:25 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

int main(void) {
	ClapTrap clean;
	ClapTrap taco("Taco");
	ClapTrap poitine("Poutine");
	ClapTrap spaghetti("Spaghetti");
	ClapTrap hamburger("Hamburger");


	taco.attack(taco.getName());
	taco.takeDamage(2);
	taco.takeDamage(2);
	taco.takeDamage(2);
	taco.takeDamage(2);
	taco.takeDamage(2);
}
