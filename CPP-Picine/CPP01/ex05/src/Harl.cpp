/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:46:53 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/15 13:25:31 by dluna-lo         ###   ########.fr       */
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
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put"
	<< " enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level){

	pointer_function[0] = &Harl::debug;
	pointer_function[1] = &Harl::info;
	pointer_function[2] = &Harl::warning;
	pointer_function[3] = &Harl::error;

	std::string data[4] = { "DEBUG", "INFO", "WARNING",  "ERROR" };

	for (size_t i = 0; i < 4; i++)
	{
		if (level == data[i])
		{
			(this->*pointer_function[i])();
			return ;
		}
	}
}
