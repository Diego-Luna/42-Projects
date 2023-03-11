/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:29:55 by diegofranci       #+#    #+#             */
/*   Updated: 2023/03/11 10:41:19 by diegofranci      ###   ########.fr       */
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
    std::cout << "\n -> value a ?:";
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
