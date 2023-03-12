/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:57:05 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/12 16:58:20 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void) {

	std::cout << "\n -- create --" << std::endl;
	Array<int>	test_one;
	Array<int>	test_two(10);
	Array<int>	test_tree(test_two);

	std::cout << "\n -- test 1 --" << std::endl;
	test_two[0] = 1;
	test_two[1] = 2;
	std::cout << "print test_two[0]: " << test_two[0] << " , test_two[1]: " << test_two[1] << std::endl;

	std::cout << "\n -- test 2 --" << std::endl;
	test_two[0] = test_two[1];
	std::cout << "print test_two[0]: " << test_two[0]
		<< " , test_two[1]: " << test_two[1]
		<< " , test_two[2]: " << test_two[2]
		<< std::endl;
	std::cout << "print test_tree[0]: " << test_tree[0]
		<< " , test_tree[1]: " << test_tree[1]
		<< " , test_tree[2]: " << test_tree[2]
		<< std::endl;

	std::cout << "\n -- test 3 --" << std::endl;
	std::cout << "\n size :test_one : " << test_one.size()
	<< "\n size :test_two : " << test_two.size()
	<< "\n size :test_tree : " << test_tree.size()
	<< std::endl;
}
