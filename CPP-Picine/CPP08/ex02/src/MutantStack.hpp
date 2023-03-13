/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:55:53 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/13 18:59:43 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
#include <stack>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
  public:
	  // Constructors and destructors
	  MutantStack(void): std::stack<T>(){};
	  MutantStack(const MutantStack &src) : std::stack<T>(src) {};
		~MutantStack(void) {}

		// Operator
    MutantStack &operator=(const MutantStack &src){
			*this = src;
			return (*this);
		}

		// typedef for all our iterators.
		typedef typename std::stack<T>::container_type::iterator iterator;

		// Iterator
		iterator end(void){
			return this->c.end();
		}
		iterator begin(void){
			return this->c.begin();
		}

  private:
};


#endif