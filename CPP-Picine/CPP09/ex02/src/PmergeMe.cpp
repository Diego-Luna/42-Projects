/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:11:26 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/26 15:46:26 by dluna-lo         ###   ########.fr       */
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

void PmergeMe::saveData(char *argv[], int argc){
	if (argc == 2){
		std::string str(argv[1]);
		// saveData_algorithme(str);
		this->original_numbers = str;
		check(str);
	}else{
		std::string tem;
		for(int i = 1; i < argc; i++){
			tem.append(" ");
			tem.append(argv[i]);
		}
		std::cout << "-> tem :" << tem << std::endl;
		// saveData_algorithme(tem);
		this->original_numbers = tem;
		check(tem);
	}
}

void PmergeMe::saveData_algorithme_one(std::string data){
	std::string tem = data;
	size_t cut_start;
	size_t cut_end;
	int number;

	// this->original_numbers = data;
	// check(data);

	for (int i = 0; i < this->numberNumbers; i++)
	{
		cut_start = findNumber(tem);
		cut_end = findSpace(tem, cut_start);
		number = std::stoll(tem.substr(cut_start, cut_end - cut_start));
		this->vec.push_back(number);
		if (cut_end < tem.length()){
			tem = tem.substr(cut_end + 1, tem.length() + 1);
		}
	}
}

void PmergeMe::saveData_algorithme_two(std::string data){
	std::string tem = data;
	size_t cut_start;
	size_t cut_end;
	int number;

	// this->original_numbers = data;
	// check(data);

	for (int i = 0; i < this->numberNumbers; i++)
	{
		cut_start = findNumber(tem);
		cut_end = findSpace(tem, cut_start);
		number = std::stoll(tem.substr(cut_start, cut_end - cut_start));
		this->dq.push_back(number);
		if (cut_end < tem.length()){
			tem = tem.substr(cut_end + 1, tem.length() + 1);
		}
	}
}

void PmergeMe::runOrganiseData(void){

	if(this->error == true){
		return;
	}

	this->start_1 = std::chrono::high_resolution_clock::now();
	// container 1
	saveData_algorithme_one(this->original_numbers);
	this->vec_2 = this->vec;
	runContainer_one(this->vec_2);
	this->end_1 = std::chrono::high_resolution_clock::now();

	this->start_2 = std::chrono::high_resolution_clock::now();
	// // container 2
	saveData_algorithme_two(this->original_numbers);
	this->dq_2 = this->dq;
	runContainer_two(this->dq_2);
	this->end_2 = std::chrono::high_resolution_clock::now();

	printResult();
}

// merge-insert sort vec
void PmergeMe::runContainer_one(std::vector<int> &vec_data){ // vector
	size_t limit = 5;

	if (vec_data.size() == 1)
		return;

	if (vec_data.size() < limit)
	{
		// organzar
		for(size_t i = 1; i < vec_data.size(); i++)
		{
			int tmp = vec_data[i];
			int j = i - 1; //accedemos a la posicion anteroir
			while(j >= 0 && vec_data[j] > tmp)
			{
				vec_data[j + 1] = vec_data[j];
				j--;
			}
			vec_data[j + 1] =  tmp;
		}
	}
	else
	{
		std::vector<int> v_L(vec_data.begin(), vec_data.begin() + (vec_data.size() / 2)); // Subvector izquierdo
		std::vector<int> v_R(vec_data.begin() + (vec_data.size() / 2), vec_data.end() ); // Subvector derecho

		// organizar
		runContainer_one(v_L);
		runContainer_one(v_R);

		// unir
		size_t i_v_L = 0;
		size_t i_v_R = 0;
		size_t i_vec_data = 0;

		while(i_v_L < v_L.size() && i_v_R < v_R.size()){
			if (v_L[i_v_L] < v_R[i_v_R]){
				vec_data[i_vec_data] = v_L[i_v_L];
				i_v_L++;
			}else{
				vec_data[i_vec_data] = v_R[i_v_R];
				i_v_R++;
			}
			i_vec_data++;
		}


		while(i_v_L < v_L.size()){
			vec_data[i_vec_data] = v_L[i_v_L];
			i_vec_data++;
			i_v_L++;
		}
		while(i_v_R < v_R.size()){
			vec_data[i_vec_data] = v_R[i_v_R];
			i_vec_data++;
			i_v_R++;
		}
	}

	this->vec = vec_data;
}

// merge-insert sort  deque
void PmergeMe::runContainer_two(std::deque<int> dq_data){ // vector

	size_t limit = 5;

	if (dq_data.size() == 1)
		return;

	if (dq_data.size() < limit)
	{
		// organzar
		for(size_t i = 1; i < dq_data.size(); i++)
		{
			int tmp = dq_data[i];
			int j = i - 1; //accedemos a la posicion anteroir
			while(j >= 0 && dq_data[j] > tmp)
			{
				dq_data[j + 1] = dq_data[j];
				j--;
			}
			dq_data[j + 1] =  tmp;
		}
	}
	else
	{
		std::vector<int> v_L(dq_data.begin(), dq_data.begin() + (dq_data.size() / 2)); // Subvector izquierdo
		std::vector<int> v_R(dq_data.begin() + (dq_data.size() / 2), dq_data.end() ); // Subvector derecho

		// organizar
		runContainer_one(v_L);
		runContainer_one(v_R);

		// unir
		size_t i_v_L = 0;
		size_t i_v_R = 0;
		size_t i_vec_data = 0;

		while(i_v_L < v_L.size() && i_v_R < v_R.size()){
			if (v_L[i_v_L] < v_R[i_v_R]){
				dq_data[i_vec_data] = v_L[i_v_L];
				i_v_L++;
			}else{
				dq_data[i_vec_data] = v_R[i_v_R];
				i_v_R++;
			}
			i_vec_data++;
		}


		while(i_v_L < v_L.size()){
			dq_data[i_vec_data] = v_L[i_v_L];
			i_vec_data++;
			i_v_L++;
		}
		while(i_v_R < v_R.size()){
			dq_data[i_vec_data] = v_R[i_v_R];
			i_vec_data++;
			i_v_R++;
		}
	}

	this->dq_2 = dq_data;
}

int PmergeMe::findSpace(std::string str, size_t start){
	for (size_t i = 0; i < str.length(); i++){
		if (i >= start && (str[i] == ' ' || str[i] == '\t')){
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