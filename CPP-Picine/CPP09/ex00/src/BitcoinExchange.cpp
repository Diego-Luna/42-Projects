/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:11:26 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/20 19:41:27 by dluna-lo         ###   ########.fr       */
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
     this->setData(c_line);
	}
  return ;
}

BitcoinExchange::~BitcoinExchange(void) {
	return;
}

std::string BitcoinExchange::setData(char* data){

	this->m1.insert(std::pair<int, std::string>(this->getMax(), data));

	this->setMax(this->getMax() + 1);
	this->setIndex(m1.begin());
}

int BitcoinExchange::getIndex(void){
	return this->itr;
}
int BitcoinExchange::setIndex(std::map<int, std::string>::iterator &itr){
	this->itr = itr;
}

int BitcoinExchange::getMax(void){
	return this->max;
}
int BitcoinExchange::setMax(int newMax){
	this->max = newMax;
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

