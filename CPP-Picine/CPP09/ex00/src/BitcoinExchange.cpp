/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:11:26 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/23 08:38:56 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	this->max = 0;
	this->name = "none";
	return ;
}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile)
{
  std::string c_line;
  size_t len = 0;

	std::ifstream input_file(databaseFile);

	while (std::getline(input_file, c_line)) {
		if (len > 0)
		{
			m1.insert(std::pair<int, std::string>(len, c_line));
		}
		len++;
	}

	this->max = len;
	this->name = databaseFile;
  return ;
}

void BitcoinExchange::runData(void){
	// std::string read;
	std::string date;
	std::string number;

	try{
		if (this->max <= 1)
		{
			throw fileError();
		}
	}	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
		return;
	}


	std::ifstream input_file(this->name);

	for (itr = m1.begin(); itr != m1.end(); ++itr)
	{
		try
		{
				checkMount(itr->second);
				date = (itr->second.substr(0, itr->second.find(' ')));
				number = itr->second.substr(itr->second.find('|') + 1, itr->second.length());
				std::cout << date << " => " << std::stoi(number) << " = " << 0.9 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

BitcoinExchange::~BitcoinExchange(void) {
	return;
}

bool BitcoinExchange::checkMount(std::string& data){

	if (data.find('|') == std::string::npos ||
				numberCaracterRepeat(data, '|') != 1 ||
				numberCaracterRepeat(data, '-') != 2 ||
				numberCaracterRepeat(data, ' ') != 2 ||
				data.find('|') != 11){
		throw formatWrong();
	}
	if (_checkdata(data) == false){ // find caracter, check data
		throw dataError();
	}
	if (_checkvalue(data) == false){ // find caracter, check number
		throw formatWrong();
	}
	return true;
}

bool BitcoinExchange::_checkvalue(std::string& data){
	std::string value = data.substr(data.find('|') + 1, data.length());

	int numberMount = std::stoi(value);

	for (size_t i = 0; i < value.length(); i++)
	{
		if (!(value[i] == ' '))
		{
				if (!(value[i] >= '0' && value[i] <= '9'))
					return false;
		}
	}
	if (numberMount > 1000 )
	{
		return false;
	}
	return true;
}

bool BitcoinExchange::_checkdata(std::string& data){
	int numberYear = std::stoi(data.substr(0, 4));
	int numberMount = std::stoi(data.substr(5, 7));
	int numberDay = std::stoi(data.substr(8, 10));

  // // Convertir el fragmento a un valor entero
	if (data[4] != '-' || data[7] != '-'){
		return (false);
	}
	// // year
	for (size_t i = 0; i < 4; i++)
	{
		if (!(data[i] >= '0' && data[i] <= '9'))
		{
			return (false);
		}
	}
	// // mount
	for (size_t i = 5; i <= 6; i++)
	{
		if (!(data[i] >= '0' && data[i] <= '9'))
		{
			return (false);
		}
	}
	if (numberMount > 12)
	{
		return (false);
	}
	// day
	for (size_t i = 8; i <= 9; i++)
	{
		if (!(data[i] >= '0' && data[i] <= '9'))
		{
			return (false);
		}
	}
	if ((numberMount == 1 || numberMount == 3 || numberMount == 5 || numberMount == 7 || numberMount == 8 || numberMount == 10 || numberMount == 12 ) && numberDay > 31){
		return false;
	}
	if ((numberMount == 4 || numberMount == 6 || numberMount == 9 || numberMount == 11 ) && numberDay > 30){
		return false;
	}


	if (numberYear % 4 == 0 && numberMount == 2 && numberDay != 29)
	{
		return false;
	}
	else if (numberMount == 2 && numberDay != 28) {
		return false;
	}

	return true;
}

int BitcoinExchange::numberCaracterRepeat(std::string& data, char c){
	int caracterRepit = 0;

	for (size_t i = 0; i < data.length(); i++)
	{
		if (data[i] == c)
		{
			caracterRepit++;
		}
	}
	return (caracterRepit);
}


// try{} cath{}
const char* BitcoinExchange::formatWrong::what() const throw() {
    return "Each line in this file must use the following format: 'data | value' ";
}

const char* BitcoinExchange::dataError::what() const throw() {
    return "A valid data will always be in the following format: Year-Month-Day.";
}

const char* BitcoinExchange::valueError::what() const throw() {
    return "A valid value must be either a float or a positive integer between 0 and 1000.";
}

const char* BitcoinExchange::fileError::what() const throw() {
    return "Error: could not open file.";
}

