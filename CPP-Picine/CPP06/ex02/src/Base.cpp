/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:45:15 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/10 18:18:37 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base() {
}

Base* generate(void){
	Base* tem;
	std::srand(time(NULL));
	int random = (rand() % 3) + 1;
	switch(random)
	{
		case 1:
			std::cout << "Created A." << std::endl;
			tem = new A();
			break;
		case 2:
			std::cout << "Created B." << std::endl;
			tem = new B();
			break;
		case 3:
			std::cout << "Created C." << std::endl;
			tem = new C();
			break;
	}
	return tem;
}

void identify(Base* p){
	try {
   if( dynamic_cast<A *>(p))
   	std::cout << "A Identified" << std::endl;
   if( dynamic_cast<B *>(p))
   	std::cout << "B Identified" << std::endl;
   if( dynamic_cast<C *>(p))
   	std::cout << "C Identified" << std::endl;
  }
	catch (...) {}
}

void identify(Base& p){
	try {
    Base & tem = dynamic_cast<A &>(p);
    std::cout << "A Identified" << std::endl;
    (void) tem;
  } catch (...) {}
	 try {
    Base & tem = dynamic_cast<B &>(p);
    std::cout << "B Identified" << std::endl;
    (void) tem;
  } catch (...) {}
	 try {
    Base & tem = dynamic_cast<C &>(p);
    std::cout << "C Identified" << std::endl;
    (void) tem;
  } catch (...) {}
}