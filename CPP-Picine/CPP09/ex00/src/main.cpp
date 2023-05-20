/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:00:50 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/20 09:56:02 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>


int main(int argc, char const *argv[])
{
	std::ifstream inputFile(argv[1]);
	if (argc != 2 || inputFile.is_open() == false)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	return 0;
}
