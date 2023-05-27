/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:00:50 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/27 17:46:45 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;

		return (1);
	}
	std::ifstream inputFile(argv[1]);
	std::ifstream database("data.csv");
	if (database.is_open() == false)
	{
		std::cerr << "Error: database not found." << std::endl;
		return (1);
	}
	if (inputFile.is_open() == false)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	BitcoinExchange bitcon(argv[1]);
	BitcoinExchange bitcon_2("ini2.txt");
	BitcoinExchange bitcon_3(bitcon);

	bitcon = bitcon_2;


	bitcon_3.runData();

	return 0;
}
