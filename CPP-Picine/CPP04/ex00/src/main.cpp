/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:26:57 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/21 13:20:42 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {

	std::cout << "*************** Animals ***************" << std::endl;
	const Animal* animal = new Animal();
	const Animal* c = new Cat();
	const Animal* d = new Dog();
	std::cout << " -> Cat -> getType : " << c->getType() << " " << std::endl;
	std::cout << " -> Dog -> getType : " << d->getType() << " " << std::endl;
	c->makeSound(); //will output the cat sound!
	d->makeSound();
	animal->makeSound();

	std::cout << " -> clean" << std::endl;
	delete animal;
	delete c;
	delete d;

	std::cout << "\n *************** WrongAnimal ***************" << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();
	std::cout << " -> getType : " << wc->getType() << " " << std::endl;
	wc->makeSound();
	wrongAnimal->makeSound();

	std::cout << " -> clean" << std::endl;
	delete wrongAnimal;
	delete wc;

	return 0;
}
