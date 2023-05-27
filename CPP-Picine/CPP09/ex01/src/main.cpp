/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:00:50 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/27 18:24:20 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>
#include <array>

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

  std::string data(argv[1]);

	if (data.length() == 0)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

	RPN promgram;

	promgram.saveInfo(data);
	promgram.getResult();

	return 0;
}