/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:56:45 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/12 16:58:08 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./iter.hpp"

int main(void) {

  std::cout << "\n -- test 1 --" << std::endl;
  std::string lista1[3] = {"Tacos 🌮","Hambuerger 🍔","ramen 🍜"};
	iter(lista1, 3, print);

  std::cout << "\n -- test 2 --" << std::endl;
  int lista2[3] = { 1, 2, 3};
	iter(lista2, 3, print);
	return (0);
}
