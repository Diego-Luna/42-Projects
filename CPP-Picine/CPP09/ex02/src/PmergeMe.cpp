/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:11:26 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/25 13:20:15 by dluna-lo         ###   ########.fr       */
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
	std::string tem = data;
	size_t cut_start;
	size_t cut_end;
	int number;

	this->original_numbers = data;
	check(data);

	for (int i = 0; i < this->numberNumbers; i++)
	{
		cut_start = findNumber(tem);
		cut_end = findSpace(tem);
		number = std::stoll(tem.substr(cut_start, cut_end - cut_start));
		std::cout << "number :" << number  << std::endl;
		this->vec.push_back(number);
		this->dq.push_back(number);

		if (cut_end < tem.length()){
			tem = tem.substr(cut_end + 1, tem.length() + 1);
		}
		std::cout << "tem :" << tem  << std::endl;
	}
	std::cout << std::endl;
}

void PmergeMe::runOrganiseData(void){
	this->start_1 = std::chrono::high_resolution_clock::now();
	// container 1
	runContainer_one();
	this->end_1 = std::chrono::high_resolution_clock::now();

	this->start_2 = std::chrono::high_resolution_clock::now();
	// // container 2
	runContainer_two();
	this->end_2 = std::chrono::high_resolution_clock::now();

	printResult();
}

void PmergeMe::runContainer_one(void){ // vector

	int temp;
	std::vector<int>::iterator i;
	std::vector<int>::iterator j;

	for(i = this->vec.begin(); i < this->vec.end(); i++) {
  	for(j = i + 1; j < this->vec.end(); j++)
  	{
  		if(*j < *i) {
  		   temp = *i;
  		   *i = *j;
  		   *j = temp;
  		}
  	}
	}
}

void PmergeMe::runContainer_two(void){ // vector

	int temp;
	std::deque<int>::iterator i;
	std::deque<int>::iterator j;

	for(i = this->dq.begin(); i < this->dq.end(); i++) {
  	for(j = i + 1; j < this->dq.end(); j++)
  	{
  		if(*j < *i) {
  		   temp = *i;
  		   *i = *j;
  		   *j = temp;
  		}
  	}
	}
}

int PmergeMe::findSpace(std::string str){
	for (size_t i = 0; i < str.length(); i++){
		if (str[i] == ' ' || str[i] == '\t'){
			return (i);
		}
	}
	return (str.length());
}
int PmergeMe::findNumber(std::string str){
	for (size_t i = 0; i < str.length(); i++){
		if (str[i] >= '0' && str[i] <= '9'){
			return (i);
		}
	}
	return (0);
}

void PmergeMe::check(std::string str){
	try
	{
		for (size_t i = 0; i < str.length(); i++)
		{
			if(!((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '\t')){
				throw Error();
			}
		}
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9' && (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0')){
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
	if (this->error == true)
		return;

	std::vector<int>::iterator i;

	std::cout << "Before:	" << this->original_numbers << std::endl;
	std::cout << "After:	";
	for (i = this->vec.begin(); i < this->vec.end(); i++){
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	std::chrono::duration<long long, std::ratio<1, 1000000000> > duration_1 = std::chrono::duration_cast<std::chrono::nanoseconds>(this->end_1 - this->start_1);
	std::chrono::duration<long long, std::ratio<1, 1000000000> > duration_2 = std::chrono::duration_cast<std::chrono::nanoseconds>(this->end_2 - this->start_2);

	std::cout << " Time to process a range of "<< this->numberNumbers << " elements with std::vector : " << duration_1.count() << " us" << std::endl;
	std::cout << " Time to process a range of "<< this->numberNumbers << " elements with std::deque  : " << duration_2.count() << " us" << std::endl;
}

const char* PmergeMe::Error::what() const throw() {
    return "Error";
}