/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:47:15 by diegofranci       #+#    #+#             */
/*   Updated: 2023/02/09 10:12:03 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

// constructor
PhoneBook::PhoneBook(void) : _max_contacts(8), _nb_contacts(0){
	std::cout << "Phonebook created" << std::endl;
}

// destroyed
PhoneBook::~PhoneBook(void){
	std::cout << "Phonebook destroyed" << std::endl;
}

void PhoneBook::start_phonebook(void){
	std::string	buffer;

	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|      [ADD]      [SEARCH]      [EXIT]      |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	while (1)
	{
		std::cout << "PhoneBook > ";
		std::getline(std::cin, buffer);
		if (buffer == "EXIT")
			return ;
		else if (buffer == "SEARCH")
			this->_search_contact();
		else if (buffer == "ADD")
			this->_add_contact();
		else
			continue ;
	}
}

void PhoneBook::_add_contact(void){
	// int i = -1;

	// this->_nb_contacts++;
	// if (this->_nb_contacts > this->_max_contacts)
	// {
		// while (++i < 7)
		// 	this->_contacts[i] = this->_contacts[i + 1];
		// this->_nb_contacts--;
	// }
	// create contant();
}

void PhoneBook::_search_contact(void){
	std::string	buffer;
	int index = -1;
	if (this->_nb_contacts == 0)
	{
		std::cout << "Phonebook is empty" << std::endl;
		return ;
	}
	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|     Index| FirstName|  LastName|  NickName|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	for (int i = 0 ; i != this->_nb_contacts ; i++)
		// print contanct
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	while (std::isdigit(buffer[0]) == 0)
	{
		std::cout << "Search > ";
		std::getline(std::cin, buffer);
	}
	index = std::stoi(buffer);
  (void)index;
  (void)this->_max_contacts;
	// if (index <= this->_nb_contacts && index > 0)
	// 	// print contanct
	// else
	// 	std::cout << "Contact not found" << std::endl;
}
