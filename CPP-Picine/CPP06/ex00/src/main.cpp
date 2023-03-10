/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:06:35 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/08 20:51:32 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int main(int n_arg, char **t_string) {

	(void)n_arg;
	(void)t_string;
	if (n_arg != 2)
	{
		std::cerr << "Error only one argument" << std::endl;
		return (1);
	}
}
