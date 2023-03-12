/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:55:19 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/12 16:57:55 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
# include <string>

int main(void) {

  bool again = true;
  std::string	msg;

  std::string a;
	std::string b;

  while (again)
  {

    std::cout << "\n -> value a ?:";
	  std::cin >> a;
    std::cout << "\n -> value b ?:";
	  std::cin >> b;

    std::cout << "\n -- test 1 --" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;
  	std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
	  std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;

    std::cout << "\n -- test 2 --" << std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
  	std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
	  std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;

    std::cout << "\n -> try again? [yes][no]";
	  std::cin >> msg;
    if (msg == "yes" || msg == "y")
    {
      again = true;
    }
    else
    {
      again = false;
    }
  }
}
