/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:46:51 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/15 16:24:50 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

int main(int argn, char **argv) {

	Harl tem;
	std::string level;

	if 	(argn == 2){
		tem.complain(argv[1]);
	}else
	{
		tem.complain("argv");
	}
}
