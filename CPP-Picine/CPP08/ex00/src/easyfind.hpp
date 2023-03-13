/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:52:53 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/13 15:34:01 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
	#define EASYFIND_HPP

#include <iostream>

template <typename T>
typename T::iterator	easyfind(T &container, int compare) {

	typename T::iterator it;
  for(it = container.begin(); it < container.end(); it++)
  {
      if (*it == compare){
				return it;
			}
  }
	throw std::logic_error("no find");
	return it;
}

#endif