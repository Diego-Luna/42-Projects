/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:51:21 by diegofranci       #+#    #+#             */
/*   Updated: 2023/03/11 11:08:58 by diegofranci      ###   ########.fr       */
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