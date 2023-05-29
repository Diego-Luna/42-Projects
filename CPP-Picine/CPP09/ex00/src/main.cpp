/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:00:50 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/29 15:35:09 by dluna-lo         ###   ########.fr       */
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

	bitcon.runData();

	return 0;
}
