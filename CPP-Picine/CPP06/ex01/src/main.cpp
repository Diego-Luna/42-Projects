/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:35:05 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/10 17:38:39 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Data.hpp"

int main(void) {
  Data * data = new Data;
	std::string s = "How many tacos?";
  int n = 10;

  data->name = s;
  data->i = n;
  uintptr_t r;
  std::cout << data->name << std::endl;
  std::cout << data->i << std::endl;
  r = serialize(data);

  Data * bla;

  bla = deserialize(r);
  std::cout << bla->name << std::endl;
  std::cout << bla->i << std::endl;
  delete data;
}
