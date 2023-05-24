/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:11:28 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/24 15:55:09 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include <forward_list>

// container map. en el constructor chechar datos
// save info y correr.
class PmergeMe
{
  public:
		PmergeMe(void);
    ~PmergeMe(void);

  private:
    int numberNumbers;

    std::vector<int> vec;
    high_resolution_clock::time_point start_1;
    high_resolution_clock::time_point end_1;

    forward_list<int> fr_lst;
    high_resolution_clock::time_point start_2;
    high_resolution_clock::time_point end_2;
};

#endif