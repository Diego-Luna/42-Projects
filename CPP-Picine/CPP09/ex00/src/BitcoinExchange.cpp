/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:11:26 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/21 18:34:25 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	this->max = 0;
	return ;
}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile)
{
	this->max = 0;

  char* c_line = nullptr;
  size_t len = 0;

	std::ifstream input_file(databaseFile);

	while ((std::getline(input_file, c_line)) != -1) {
		if ()
	}
  return ;
}

BitcoinExchange::~BitcoinExchange(void) {
	return;
}

bool checkMount(std::string& data){

	if (str.find('|') == std::string::npos){ // find caracter
		throw formatWrong();
	}
	else if (str.find('|') != 11  ){ // find caracter
		throw formatWrong();
	}
	else if ((str.length() - str.find('|'))  ){ // find caracter
		throw formatWrong();
	}


}


// try{} cath{}
const char* BitcoinExchange::formatWrong::what() const throw() {
    return "Each line in this file must use the following format: 'date | value' ";
}

const char* BitcoinExchange::dateError::what() const throw() {
    return "A valid date will always be in the following format: Year-Month-Day.";
}

const char* BitcoinExchange::valueError::what() const throw() {
    return "A valid value must be either a float or a positive integer between 0 and 1000.";
}

