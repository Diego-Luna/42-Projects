/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:56:17 by diegofranci       #+#    #+#             */
/*   Updated: 2023/03/11 11:15:12 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./iter.hpp"

int main(void) {

  std::cout << "\n -- test 1 --" << std::endl;
  std::string lista1[3] = {"Tacos 🌮","Hambuerger 🍔","ramen 🍜"};
	::iter(lista1, 3, print);

  std::cout << "\n -- test 2 --" << std::endl;
  int lista2[3] = { 1, 2, 3};
	::iter(lista2, 3, print);
	return (0);
}
