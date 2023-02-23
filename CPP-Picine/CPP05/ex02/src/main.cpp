/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:42:18 by diegofranci       #+#    #+#             */
/*   Updated: 2023/02/23 14:25:03 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
  std::cout << "-----------------ShrubberyCreationForm-----------------" << std::endl;
	Bureaucrat dixie("dixie", 20);
	ShrubberyCreationForm form1("Christmas_tree");
	try
	{
		std::cout << dixie;
		dixie.signForm(form1);
		dixie.executeForm(form1);
		std::cout << std::endl;

		std::cout << form1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n-----------------RobotomyRequestForm-----------------" << std::endl;
	Bureaucrat lala("lala", 46);
	RobotomyRequestForm form2("po");
	try
	{
		std::cout << lala << std::endl;
		lala.signForm(form2);
		lala.executeForm(form2);
		dixie.executeForm(form2);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n-----------------PresidentialPardonForm-----------------" << std::endl;
	try
	{
		Bureaucrat tinky("tinky", 25200);
		PresidentialPardonForm form3("winky");
		std::cout << tinky;
		lala.signForm(form3);
		tinky.signForm(form3);
		tinky.executeForm(form3);
		form3.execute(tinky);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

    return 0;
}