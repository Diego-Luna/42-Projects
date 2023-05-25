/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:11:26 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/25 19:12:37 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPN::RPN(void)
{
	this->result = 0;
	this->error = false;
	this->numberNumbers = 0;
	return;
}

RPN::~RPN(void) {
	return;
}

void RPN::saveInfo(std::string& data){
	std::string& save = data;
	this->numberNumbers = 0;

	size_t cut_start = 0;
	size_t cut_end = 0;

	this->it = this->arr.begin();
	try{
		checkData(data);
		// save in array;
		while(cut_end < save.length())
		{
			positionFind(data, &cut_start, &cut_end);
			*this->it = data.substr(cut_start, cut_end - cut_start);
			(data.length() == 0)? throw Error() : true ;
			cut_start = cut_end;
			this->it++;
		}
		this->it = this->arr.begin();
	}	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
		this->error = true;
	}
}

void RPN::getResult(void){

	int i = 0;

	if (error == true){
			return;
	}
	try
	{
		if (isStringNumber(this->arr[0]) == false || ( this->arr[1].length() > 0 && isStringNumber(this->arr[1]) == false))
		{
			throw Error();
		}

		// for (size_t full = 0; full < 20; full++)
		// {
		// 	this->tem_arr[full] = 0;
		// }
		for (this->tem_it = this->tem_arr.begin(); this->tem_it != this->tem_arr.end(); this->tem_it++)
    {
				*this->tem_it = 0;
		}

		this->tem_it = this->tem_arr.begin();

		for(this->it = this->arr.begin(); this->it < this->arr.end(); this->it++)
		{
			if (isStringNumber(*this->it) == true)
			{
				*this->tem_it = std::stoi(*this->it);
				this->tem_it++;
				this->numberNumbers++;
			}
			else if ((*this->it).length() > 0) {
				if ((*this->it) == "+" ){
					// this->tem_arr[i - 2] = this->tem_arr[i - 2] + this->tem_arr[i - 1];
					*(this->tem_it - 2) = *(this->tem_it - 2) + *(this->tem_it - 1);
				}
				else if ((*this->it) == "-" ){
					this->tem_arr[i - 2] = this->tem_arr[i - 2] - this->tem_arr[i - 1];
				}else if ((*this->it) == "*" ){
					this->tem_arr[i - 2] = this->tem_arr[i - 2] * this->tem_arr[i - 1];
				}else if ((*this->it) == "/" ){
					this->tem_arr[i - 2] = this->tem_arr[i - 2] / this->tem_arr[i - 1];
				}
				this->result = *(this->tem_it - 2);
				*( this->tem_it - 1) = 0;
				this->tem_it--;
				// i--;
				// this->result = this->tem_arr[i - 2];
				// this->tem_arr[i - 1] = 0;
				// i--;
			}
		}
		// for(this->it = this->arr.begin(); this->it < this->arr.end(); this->it++)
		// {
		// 	if (isStringNumber(*this->it) == true)
		// 	{
		// 		this->tem_arr[i] = std::stoi(*this->it);
		// 		i++;
		// 		this->numberNumbers++;
		// 	}
		// 	else if ((*this->it).length() > 0) {
		// 		if ((*this->it) == "+" ){
		// 			this->tem_arr[i - 2] = this->tem_arr[i - 2] + this->tem_arr[i - 1];
		// 		}
		// 		else if ((*this->it) == "-" ){
		// 			this->tem_arr[i - 2] = this->tem_arr[i - 2] - this->tem_arr[i - 1];
		// 		}else if ((*this->it) == "*" ){
		// 			this->tem_arr[i - 2] = this->tem_arr[i - 2] * this->tem_arr[i - 1];
		// 		}else if ((*this->it) == "/" ){
		// 			this->tem_arr[i - 2] = this->tem_arr[i - 2] / this->tem_arr[i - 1];
		// 		}
		// 		this->result = this->tem_arr[i - 2];
		// 		this->tem_arr[i - 1] = 0;
		// 		i--;
		// 	}
		// }
		if (i != 1)
		{
			for(this->tem_it = this->tem_arr.begin(); this->tem_it < this->tem_arr.end(); this->tem_it++){
				(*this->tem_it > 0 )? std::cout << *this->tem_it: true;
			}
		}
		else{
			std::cout << this->result << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		this->error = true;
	}

}


bool RPN::isStringNumber(std::string& str){
	if (str.length() == 0)
		return false;
	for(size_t i = 0; i < str.length(); i++){
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return false;
		}
	}
	return true;
}

void RPN::positionFind(std::string& data, size_t *cut_start, size_t *cut_end)
{
	while (data[*cut_start] && *cut_start < data.length() && data[*cut_start] == ' ')
	{
		(*cut_start)++;
	}
	*cut_end = *cut_start + 1;
	while ( data[*cut_end] && *cut_end  < data.length() && data[*cut_end] != ' ')
	{
		(*cut_end)++;
	}
}

bool RPN::checkData(std::string& data){
	int numberOfNumbers = 0;
	// check number y space,
	(data.length() == 0)? throw Error() : true ;
	for (size_t i = 0; i < data.length(); i++)
	{
		if (!((data[i] >= '0' && data[i] <= '9') || data[i] == ' ' || data[i] == '+' || data[i] == '-' || data[i] == '/' || data[i] == '*'))
		{
			throw Error();
		}
	}
	// check number of numbers
	for (size_t i = 0; i < data.length(); i++)
	{
		if (data[i] >= '0' && data[i] <= '9' && data[i + 1] == ' '){
			numberOfNumbers++;
		}
	}
	(numberOfNumbers >= 10)? throw Error() : true ;

	return true;
}

const char* RPN::Error::what() const throw() {
    return "Error";
}
