/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:55:15 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/10 09:16:31 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion(std::string str): _str(str), _isNumber(false), _nbr(0)
{
}

Conversion::Conversion(const Conversion & src) :_str(src._str), _nbr(src._nbr), _isNumber(src._isNumber)
{
}

Conversion::~Conversion()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

void				Conversion::detectType() const{
	
}
void				Conversion::printResult() const{
	(_nbr >= 32 && _nbr <= 126)? (std::cout << "char : " << static_cast<char>(_nbr) << std::endl) : (std::cout << "char : Non displayable" << std::endl);
	if (_isNumber){
	 	std::cout << "int: " << static_cast<int>(this->_nbr)  << std::endl;
		std::cout << "float: " <<  static_cast<float>(this->_nbr) << std::endl;
		std::cout << "double: " <<  static_cast<double>(this->_nbr) << std::endl;
	}
	else{
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}