/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:11:26 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/27 17:44:18 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	this->max = 0;
	this->name = "none";
	return ;
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy){
	this->max = copy.max ;
  this->name = copy.name ;
  this->_errorMessage = copy._errorMessage ;

  this->m1 = copy.m1 ;
  this->itr = copy.itr ;
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
		// std::cout << e.what() << '\n';
		std::cout << e.what() << std::endl;;
		return;
	}


	std::ifstream input_file(this->name);

	for (itr = m1.begin(); itr != m1.end(); ++itr)
	{
		// try
		// {
				if (checkMount(itr->second) == true)
				{
					date = (itr->second.substr(0, itr->second.find(' ')));
					number = itr->second.substr(itr->second.find('|') + 1, itr->second.length());
					std::cout << date << " => " << std::stof(number) << " = " << (std::stof(number) * getNumberOfDataset(date)) << std::endl;
				}
		// }
		// catch(const std::exception& e)
		// {
		// 	std::cout << e.what() << date << " | "<< number << '\n';
		// }
	}
}

BitcoinExchange::~BitcoinExchange(void) {
	return;
}

bool BitcoinExchange::checkMount(std::string& data){

	if (data.length() == 0){
		return false;
	}

	try
	{
		if (_checkdata(data) == false){ // find caracter, check data
			throw formatWrong();
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << data << std::endl;
		return false;
	}

	try{
		if (data.length() == 0){
			return false;
		}

		if (_checkvalue(data) == false){ // find caracter, check number
			throw valueError();
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		// std::cout << e.what() << data << '\n';
		return false;
	}

	try
	{
		if (data.find('|') == std::string::npos ||
				numberCaracterRepeat(data, '|') != 1 ||
				numberCaracterRepeat(data, '-') != 2 ||
				numberCaracterRepeat(data, ' ') != 2 ||
				data.find('|') != 11){
					throw formatWrong();
			}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}

	return true;
}

bool BitcoinExchange::_checkvalue(std::string& data){
	std::string value = data.substr(data.find('|') + 1, data.length());
	int numberMount = std::stoll(value);
	int number_point = 0;


	if (value.length() > 3){
		return false;
	}
	if (numberMount < 0)
	{
			throw negativetWrong();
	}

	for (size_t i = 0; i < value.length(); i++)
	{
		if (value[i] == '.'){
				number_point++;
		}
		else if (!(value[i] == ' '))
		{
			if (!(value[i] >= '0' && value[i] <= '9') || number_point > 1)
				return false;
		}
	}
	if (numberMount > 1000)
	{
		return false;
	}
	return true;
}

bool BitcoinExchange::_checkdata(std::string& data){

	// (void)data;
	int numberYear = std::stoll(data.substr(0, 4));
	int numberMount = std::stoll(data.substr(5, 2));
	int numberDay = std::stoll(data.substr(8, 2));

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

	if (numberYear % 4 == 0 && numberMount == 2 && numberDay > 29)
	{
		return false;
	}
	else if ( numberYear % 4 == 1  && numberMount == 2 && numberDay != 28) {
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

float BitcoinExchange::getNumberOfDataset(std::string& date){
	int  c_year = std::stoll(date.substr(0, 4));
	int  c_mount = std::stoll(date.substr(5, 2));
	int  c_day = std::stoll(date.substr(8, 2));

	size_t i = 0;

	std::string c_line;
	std::string temp = "";

	std::ifstream input_file("data.csv");

	// read
	std::getline(input_file, c_line);

	// value in int
	int c_line_year = 0;
	int c_line_mount = 0;
	int c_line_day = 0;

	while (std::getline(input_file, c_line)) {

		c_line_year = std::stoll(c_line.substr(0, 4));
		c_line_mount = std::stoll(c_line.substr(5, 2));
		c_line_day = std::stoll(c_line.substr(8, 2));

		if (i == 0 && c_year < c_line_year){
			throw databaseError();
		}
		i++;

		if (c_line_year == c_year &&
				c_line_mount == c_mount &&
				c_line_day == c_day)
		{
				return (std::stof(c_line.substr(11, c_line.length())));
		}
		else if(
				c_line_year >= c_year &&
				c_line_mount >= c_mount &&
				c_line_day >= c_day
				)
		{
			return (std::stof(temp.substr(11, temp.length())));
		}
		else
		{
			temp = c_line;
		}
	}

	if (
		c_line_year < c_year
	)
	{
		return (std::stof(temp.substr(11, temp.length())));
	}

	throw databaseError();
	return -1;
}

int BitcoinExchange::aNumbers(int number){
	if (number < 0 )
	{
		return (-number);
	}
	return number;
}

// try{} cath{}
const char* BitcoinExchange::formatWrong::what() const throw() {
  return "Error: bad input => ";
}

const char* BitcoinExchange::dataError::what() const throw() {
    return "Error: A valid data will always be in the following format: Year-Month-Day : ";
}

const char* BitcoinExchange::valueError::what() const throw() {
    return "Error: too large a number.";
}

const char* BitcoinExchange::fileError::what() const throw() {
    return "Error: could not open file.";
}

const char* BitcoinExchange::databaseError::what() const throw() {
    return "Error: database error :" ;
}

const char* BitcoinExchange::negativetWrong::what() const throw() {
    return "Error: not a positive number." ;
}


BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (this != &copy)
    {
      this->max = copy.max;
  		this->name = copy.name;
  		this->_errorMessage = copy._errorMessage;

  		this->m1 = copy.m1;
  		this->itr = copy.itr;
    }
    return *this;
}