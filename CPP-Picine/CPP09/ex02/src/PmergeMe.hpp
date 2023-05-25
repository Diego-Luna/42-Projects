/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:11:28 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/25 10:38:42 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include <forward_list>
#include <chrono>

// container map. en el constructor chechar datos
// save info y correr.
class PmergeMe
{
  public:
		PmergeMe(void);
		PmergeMe(std::string data);
    ~PmergeMe(void);

    void saveData(std::string data);
    void runOrganiseData(void);


    // Error -> try cath
		class Error : public std::exception {
    public:
        virtual const char* what() const throw();
    };

  private:
    int numberNumbers;
    bool error;
    std::string original_numbers;
    std::string organized_numbers;

    std::vector<int> vec;
    std::chrono::high_resolution_clock::time_point start_1;
    std::chrono::high_resolution_clock::time_point end_1;

    std::forward_list<int> fr_lst;
    std::chrono::high_resolution_clock::time_point start_2;
    std::chrono::high_resolution_clock::time_point end_2;

    void runContainer_one(std::string original_numbers);
    void runContainer_two(std::string original_numbers);
    void printResult(void);
    void check(std::string str);
};

#endif