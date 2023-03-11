/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:21:05 by diegofranci       #+#    #+#             */
/*   Updated: 2023/03/11 14:13:10 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		_array = new T[0];
		_size = 0;
	}
	Array(unsigned int n)
	{
		_array = new T[n];
		_size = n;
	}
	Array(Array const &src)
	{
		*this = src;
	}
	~Array(void)
	{
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
  T &operator[](unsigned int i)
	{
		if (i >= _size)
			throw std::exception();
		return (_array[i]);
	}
};
