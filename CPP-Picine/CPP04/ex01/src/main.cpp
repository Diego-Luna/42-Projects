/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:56:04 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/21 13:32:05 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {

	int number;

	std::cout << "*************** Animals ***************" << std::endl;
	std::cout << "How many animals? (only positive and even numbers): ";
	std::cin >> number;


	if (number <= 1){
		std::cout << "only positive and even numbers" << std::endl;
		return 0;
	}
	if (number % 2 == 1){
		std::cout << "only positive and even numbers" << std::endl;
		return 0;
	}

	Animal *animals[number];

	std::cout << "\n-> create dogs" << std::endl;
	for(int i = 0; i < (number / 2); i++){
		animals[i] = new Dog();
	}
	std::cout << "\n-> create cats" << std::endl;
	for(int i = (number / 2); i < number; i++){
		animals[i] = new Cat();
	}

	std::cout << "\n--> makeSound dogs" << std::endl;
	for(int i = 0; i < (number / 2); i++){
		animals[i]->makeSound();
	}
	std::cout << "\n--> makeSound cats" << std::endl;
	for(int i = (number / 2); i < number; i++){
		animals[i]->makeSound();
	}


	std::cout << "\n---> clean dogs" << std::endl;
	for(int i = 0; i < (number / 2); i++){
		delete animals[i];
	}
	std::cout << "\n---> clean cats" << std::endl;
	for(int i = (number / 2); i < number; i++){
		delete animals[i];
	}

	return 0;
}
