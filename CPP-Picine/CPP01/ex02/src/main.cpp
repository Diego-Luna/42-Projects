/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:08:29 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/14 12:35:06 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

int main(void) {
	std::string 	string_one = "HI_THIS_IS_BRAIN";
	std::string 	*stringPTR = &string_one;
	std::string 	&stringREF = string_one;

	std::cout << "\nThe memory address of the string variable. = " << &string_one << std::endl;
	std::cout << "\nThe memory address held by stringPTR. = " << &stringPTR << std::endl;
	std::cout << "\nThe memory address held by stringREF. = " << &stringREF << std::endl;
	
	std::cout << "\nThe value of the string variable. = " << string_one << std::endl;
	std::cout << "\nThe value pointed to by stringPTR. = " << *stringPTR << std::endl;
	std::cout << "\nThe value pointed to by stringREF. = " << stringREF << std::endl;
}
