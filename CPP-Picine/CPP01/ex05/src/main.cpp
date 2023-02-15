/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:18:40 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/15 13:27:21 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

int main(void) {

	Harl tem;
	std::string level;
	int again = 1;

	while (again == 1)
	{
		std::cout << "\n -> Harl level : ";
		std::cin >> level;

		tem.complain(level);

		std::cout << "\n -> try again [yes][no] :";
		std::cin >> level;
		if (level == "yes")
			again = 1;
		else
			again = 0;
	}
}
