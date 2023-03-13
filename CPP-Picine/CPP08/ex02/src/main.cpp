/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:55:56 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/13 19:27:07 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void) {
	std::cout << "\n -- test 1 --" << std::endl;
	try
	{
		MutantStack<int> test1;

		test1.push(5);
		test1.push(1);
		test1.push(4);

		std::cout << "MutantStack data:" << std::endl;
    for (MutantStack<int>::iterator it = test1.begin(); it != test1.end(); ++it)
    {
        std::cout << *it <<  " " ;
    }
		std::cout << std::endl;
		if (test1.empty()){
			std::cout << "is empty :"<< std::endl;
		}else{
			std::cout << "Size :" << test1.size() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n -- test 2 --" << std::endl;
	try
	{
		MutantStack<int> test1;

		test1.push(5);
		test1.push(1);
		test1.push(4);

		std::cout << "MutantStack data:" << std::endl;
    for (MutantStack<int>::iterator it = test1.begin(); it != test1.end(); ++it)
    {
        std::cout << *it <<  " " ;
    }
		test1.pop();
		test1.pop();
		test1.pop();
		std::cout << std::endl;
		if (test1.empty()){
			std::cout << "is empty :"<< std::endl;
		}else{
			std::cout << "Size :" << test1.size() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n -- test 3 --" << std::endl;
	try
	{
		MutantStack<int> test1;

		std::cout << " push 5 " << std::endl;
		test1.push(5);
		std::cout << " get: " << test1.top() << std::endl;
		test1.pop();

		std::cout << " push 10 " << std::endl;
		test1.push(10);
		std::cout << " get: " << test1.top() << std::endl;
		test1.pop();

		std::cout << " push 15 " << std::endl;
		test1.push(15);
		std::cout << " get: " << test1.top() << std::endl;
		test1.pop();

		std::cout << std::endl;
		if (test1.empty()){
			std::cout << "is empty :"<< std::endl;
		}else{
			std::cout << "Size :" << test1.size() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }