/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:30:23 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/13 17:52:51 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructors and destructors
Span::Span(void){
	_size = 0;
	_realy = 0;
	_is = false;
}
Span::Span(unsigned int num){
	_size = num;
	_is = false;
	_realy = 0;
}
Span::Span(const Span &src){
	// *this = src;
	_size = src._size;
	_array = src._array;
	_is = src._is;
	_realy = src._realy;
}
Span::~Span(void){

}

Span &Span::operator=(const Span &src)
{
  _array = src._array;
  _size = src._size;
  _realy = src._realy;
  _is = src._is;
  return *this;
}


// basic
void Span::check_size(std::string	msg, bool add){
	if (_is == false)
	{
		throw std::logic_error("no data");
	}

	if (add == true && (  _size <= 0 || _array.size() == _size))
	{
		throw std::logic_error(msg);
	}
	else if (add == false &&  (_size <= 1 || _realy <= 1))
	{
		throw std::logic_error(msg);
	}
}
void Span::addNumber(int add){
	_is = true;
	_realy++;
	check_size("I can't add it", true);
	_array.push_back(add);
}

int Span::shortestSpan(void){
	std::vector<int> _shortestSpan;
	int result;


	check_size("shortestSpan is not posible", false);
	std::sort(_array.begin(), _array.end());
	for (size_t i = 1; i < _size; i++)
	{
		_shortestSpan.push_back(_array[i] - _array[i - 1]);
	}


	result = *std::min_element(_shortestSpan.begin(), _shortestSpan.end());
	return result;
}

int Span::longestSpan(void){
	int result;

	check_size("longestSpan is not posible", false);
	std::sort(_array.begin(), _array.end());

	result = *std::max_element(_array.begin(), _array.end());
	result -= *std::min_element(_array.begin(), _array.end());
	return result;
}


