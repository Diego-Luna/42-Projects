/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:11:26 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/25 10:40:52 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::~PmergeMe(void) {
	return;
}

PmergeMe::PmergeMe(void)
{
	this->numberNumbers = 0;
	this->error = false;
  this->original_numbers = "";
  this->organized_numbers = "";
	return;
}

PmergeMe::PmergeMe(std::string data)
{
	this->numberNumbers = 0;
	this->error = false;
  this->organized_numbers = "";

	this->original_numbers = data;
	check(data);
	return;
}

void PmergeMe::saveData(std::string data){
	this->original_numbers = data;
	check(data);
}

void PmergeMe::runOrganiseData(void){
	printResult();
}


void PmergeMe::check(std::string str){
	try
	{
		for (size_t i = 0; i < str.length(); i++)
		{
			(!(str[i] >= '0' && str[i] <= '9'))? throw Error() : true;
		}
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9' && (str[i + 1] == ' ' || str[i + 1] == '\0')){
				this->numberNumbers++;
			}
		}
		this->error = false;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		this->error = true;
	}
}

void PmergeMe::printResult(void){
	std::cout << "Before:	" << this->original_numbers << std::endl;
	std::cout << "After:	" << this->organized_numbers << std::endl;

	std::cout << " Time to process a range of "<< this->numberNumbers << " elements with std:: " << std::endl;
	std::cout << " Time to process a range of "<< this->numberNumbers << " elements with std:: " << std::endl;
}

const char* PmergeMe::Error::what() const throw() {
    return "Error";
}