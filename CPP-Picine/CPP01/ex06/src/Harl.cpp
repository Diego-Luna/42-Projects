/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:46:53 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/15 16:23:22 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

Harl::Harl(void){
	return;
}
Harl::~Harl(void){
	return;
}

void Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void){
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put"
	<< " enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void){
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void){
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

int Harl::get_position(std::string str, std::string list[4])
{
	for (int i = 0; i < 4; i++)
	{
		if (str == list[i])
		{
			return i;
		}
	}
	return -1;
}

void Harl::complain(std::string level){

	pointer_function[0] = &Harl::debug;
	pointer_function[1] = &Harl::info;
	pointer_function[2] = &Harl::warning;
	pointer_function[3] = &Harl::error;

	std::string data[4] = { "DEBUG", "INFO", "WARNING",  "ERROR" };

	int position = get_position(level, data);

	for (int i = position; i < 4; i++)
	{
		if (level == data[i])
		{
			while(i < 4)
			{
				(this->*pointer_function[i])();
				i++;
			}
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
}
