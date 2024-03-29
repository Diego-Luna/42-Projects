/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:06:35 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/10 16:58:23 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Conversion.hpp"

int main(int n_arg, char **t_string) {

	(void)n_arg;
	(void)t_string;
	if (n_arg != 2 || !t_string[1][0])
	{
		std::cerr << "Error only one argument" << std::endl;
		return (1);
	}

	Conversion con(t_string[1]);
	con.printResult();
}
