/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:56:34 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/12 16:58:04 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T>
void	iter(T *addr, size_t leng, void (*funtion)(T const &)) {
	for (size_t i = 0; i < leng; i++)
  {
    funtion(addr[i]);
  }
}

template <typename T>
void print(T line) {
	std::cout << line << std::endl;
}

#endif