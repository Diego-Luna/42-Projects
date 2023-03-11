/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:55:15 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/10 18:27:01 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include <vector>


Conversion::Conversion(std::string str):
	_isValid(false),
	_str(str),
	_type("none")
{
	detectType();
}

Conversion::Conversion(const Conversion & src) :
	_isValid(src._isValid),
	_str(src._str),
	_type(src._type)
{
}

Conversion::~Conversion()
{
	// std::cout << "Bureaucrat destructor called" << std::endl;

}

void				Conversion::detectType() {

	if (_str.length() == 1 && _str.at(0))
	{
		_isValid = true;
		 _type = "C";
		return;
	}

	for(int i = 0; i < (int)_str.length(); i++)
	{
		if (!((_str[i] >= '0' && _str[i] <= '9') || _str[i] =='.' || (_str[i] =='f' && i > 0)))
		{
			if (_str.length() == 1 && _str.at(0))
			{
				_isValid = true;
				 _type = "C";
				return;
			}
			_isValid = false;
			return;
		}
	}
	if (_str == "-inf" || _str == "+inf" || _str == "nan") {
		return;
	}
	if (std::atoll(_str.c_str()) > INT_MAX || std::atoll(_str.c_str()) < INT_MIN)
		_isValid = false;
	else
		_isValid = true;
}

void				Conversion::printResult() {

	if (_type == "C")
	{
		printResult_in_c(_str.at(0));
	}else
	{
		printResult_all();
	}
}

void				Conversion::printResult_in_c(char c) {

	if (_isValid){
		int 

		(c >= 32 && c <= 126)? (std::cout << "char : " << static_cast<char>(c) << std::endl) : (std::cout << "char : Non displayable" << std::endl);
	 	std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " <<  static_cast<float>(c) << ".0f" << std::endl; //pointer to float
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
	else{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

void				Conversion::printResult_all() {

	std::string tem = static_cast<std::string>(_str);
	const char *pointer = tem.c_str();


	int caracter = std::atoi(pointer);
	if (_isValid){
		(caracter >= 32 && caracter <= 126)? (std::cout << "char : " << static_cast<char>(caracter) << std::endl) : (std::cout << "char : Non displayable" << std::endl);
	 	std::cout << "int: " << std::atoi(pointer) << std::endl;
		std::cout << "float: " <<  std::atof(pointer) << ((_str.find('.') != std::string::npos) ?
		 ""
			:
		  ".0"
		 )
		 << "f" << std::endl; //pointer to float
		std::cout << "double: " << static_cast<double>(std::atof(pointer)) << ((_str.find('.') != std::string::npos) ?
		 ""
			:
		  ".0"
		 )
		 << std::endl;
	}
	else{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}