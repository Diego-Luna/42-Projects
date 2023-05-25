/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:00:50 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/25 13:25:58 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "PmergeMe.hpp"

#include <iostream>
#include <array>

int main(int argc, char const *argv[])
{
	if (argc < 2 || argv[0] == '\0' )
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

  // std::string data(argv[1]);

	// PmergeMe program;

	// program.saveData(data);
	// program.runOrganiseData();

	return 0;
}
