/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:52:56 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/13 19:27:35 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <array>

int main(void) {

  bool again = true;
  std::string	msg;
  int	find;

	std::array<int, 5> arr = {10, 11, 12, 12, 13};
  std::array<int, 5>::iterator it;

  std::cout << "The array is: ";
  for(it = arr.begin(); it < arr.end(); it++)
  {
      std::cout << it << " " << *it  <<  std::endl;
  }
  std::cout << "Size of the array is: " << arr.size() << std::endl;

  while (again)
  {
    std::cout << "\n\n\n -> value find ?:";
	  std::cin >> find;

    try
    {
      std::cout << "\n -- test 1 : address in memory --" << std::endl;
      std::cout << easyfind(arr, find) << std::endl;
      std::cout << "\n -- test 2 : value--" << std::endl;
      std::cout << *easyfind(arr, find) << std::endl;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }


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
