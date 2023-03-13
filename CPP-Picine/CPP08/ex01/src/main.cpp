/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:30:25 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/13 17:54:09 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {
	std::cout << "\n -- test 1 --" << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n -- test 2, 10 000 numbers --" << std::endl;
	try
	{
		Span sp = Span(10000);
		for (size_t i = 1; i < 10001; i++)
		{
			sp.addNumber(i);
		}

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n -- test 2, copy 1, 10 000 numbers --" << std::endl;
	try
	{
		Span exm = Span(10000);
		Span sp = Span(exm);
		for (size_t i = 1; i < 2; i++)
		{
			sp.addNumber(i);
		}

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n -- test 2, copy 2 , 10 000 numbers --" << std::endl;
	try
	{
		Span exm = Span(10000);
		Span sp = Span(exm);
		for (size_t i = 1; i < 10001; i++)
		{
			sp.addNumber(i);
		}

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n -- test 2, copy =,  10 000 numbers --" << std::endl;
	try
	{
		Span exm = Span(10000);
		Span sp = Span(2);
		for (size_t i = 1; i < 10001; i++)
		{
			exm.addNumber(i);
		}

		sp = exm;

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n -- test 3, 90 000 numbers --" << std::endl;
	try
	{
		Span sp = Span(90000);
		for (size_t i = 1; i < 90001; i++)
		{
			sp.addNumber(i);
		}

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n -- test 4, size 0 and 10 000 numbers --" << std::endl;
	try
	{
		Span sp = Span(0);
		for (size_t i = 0; i < 10000; i++)
		{
			sp.addNumber(i);
		}

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n -- test 5, Error ins shortestSpan --" << std::endl;
	try
	{
		Span sp = Span(1);
		sp.addNumber(10);

		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n -- test 6, Error ins longestSpan --" << std::endl;
	try
	{
		Span sp = Span(1);
		sp.addNumber(10);

		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n -- test simple, Error ins longestSpan --" << std::endl;
	try
	{
		Span sp = Span();
		sp.addNumber(10);

		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
