/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:00:50 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/25 15:56:04 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <array>

int main(int argc, char *argv[])
{
	if (argc < 2 || argv[0] == '\0' )
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

	PmergeMe program;

	program.saveData(argv, argc);
	program.runOrganiseData();

	return 0;
}
