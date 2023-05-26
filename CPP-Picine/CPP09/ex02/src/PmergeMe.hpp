/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:11:28 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/26 15:30:16 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include <deque>
#include <chrono>

// container map. en el constructor chechar datos
// save info y correr.
class PmergeMe
{
  public:
		PmergeMe(void);
    ~PmergeMe(void);

    void saveData(char *argv[], int argc);
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
    std::vector<int> vec_2;
    std::chrono::high_resolution_clock::time_point start_1;
    std::chrono::high_resolution_clock::time_point end_1;

    std::deque<int> dq;
    std::deque<int> dq_2;
    std::chrono::high_resolution_clock::time_point start_2;
    std::chrono::high_resolution_clock::time_point end_2;

    // Bubble Sort
    void runContainer_one(std::vector<int> &vec_data);
    void runContainer_two(std::deque<int> dq_data);
    void printResult(void);
    void check(std::string str);

    int findSpace(std::string str,size_t  start);
    int findNumber(std::string str);

    void saveData_algorithme_one(std::string data);
    void saveData_algorithme_two(std::string data);

};

#endif