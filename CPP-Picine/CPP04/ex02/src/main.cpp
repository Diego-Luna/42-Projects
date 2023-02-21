/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:56:04 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/21 14:23:12 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {

	// Animal	*ani1 = new Animal();
	Cat		*cat1 = new Cat();
	Dog		*dog1 = new Dog();

	std::cout  << " -> Cat" << std::endl;
	cat1->makeSound();
	std::cout << std::endl;
	std::cout  << " -> Dog" << std::endl;
	dog1->makeSound();
	std::cout << std::endl;

	delete cat1;
	delete dog1;
	return 0;
}
