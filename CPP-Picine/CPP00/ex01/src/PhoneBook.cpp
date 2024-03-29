/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:47:15 by diegofranci       #+#    #+#             */
/*   Updated: 2023/02/11 15:50:09 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

// constructor
PhoneBook::PhoneBook(void) : _max_contacts(8), _nb_contacts(0), _nb_contacts_i(-1){
	// std::cout << "Phonebook created" << std::endl;
}

// destroyed
PhoneBook::~PhoneBook(void){
	// std::cout << "Phonebook destroyed" << std::endl;
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
	int copy = 0;

	this->_nb_contacts++;
	if (this->_nb_contacts > this->_max_contacts)
	{
		this->_nb_contacts = this->_max_contacts;
		this->_nb_contacts_i++;
		if (this->_nb_contacts_i >= this->_max_contacts)
		{
			this->_nb_contacts_i = 0;
		}
		copy = this->_nb_contacts_i;
	}
	else
	{
		copy = this->_nb_contacts - 1;
	}
	this->_contacts[copy]._create();
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
	{
		this->_contacts[i]._print_contact(i + 1);
	}
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	while (std::isdigit(buffer[0]) == 0)
	{
		std::cout << "Search > ";
		std::getline(std::cin, buffer);
	}
	index = std::stoi(buffer);
	if (index <= this->_nb_contacts && index > 0)
		this->_contacts[index - 1]._print_contact_all(index);
	else
		std::cout << "Contact not found" << std::endl;
}
