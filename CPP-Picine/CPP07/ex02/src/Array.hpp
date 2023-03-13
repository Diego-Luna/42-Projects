/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:56:59 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/13 14:43:46 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <class T>
class Array
{
private:
  T*            _array;
	unsigned int  _size;
public:
  // Construction and destructure
  Array(void)
	{
		std::cout << "-- default constructor --" << std::endl;
		_array = new T[0];
		_size = 0;
	}
	Array(unsigned int n)
	{
		std::cout << "-- unsigned int constructor --" << std::endl;
		_array = new T[n];
		_size = n;
	}
	Array(Array const &src)
	{
		std::cout << "-- copy constructor --" << std::endl;
		_size = src.size();
		_array = new T[src.size()];
		for (size_t i = 0; i < _size; i++)
		{
			_array[i] = src._array[i];
		}
	}
	~Array(void)
	{
		std::cout << "--  destructor --" << std::endl;
		delete [] _array;
	}

  unsigned int size(void) const
	{
		return (_size);
	}

  // operator
  Array &operator=(Array const &rhs)
	{
		if (this != &rhs)
		{
			delete [] _array;
			_size = rhs._size;
			_array = new T[rhs._size];
			for (unsigned int i = 0; i < rhs._size; i++)
				_array[i] = rhs._array[i];
		}
		return (*this);
	}

  T &operator[](unsigned int i) const
	{
		if (i >= _size)
			throw std::exception();
		return (_array[i]);
	}
};
